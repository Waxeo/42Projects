
function startTournament() {
	
	let winner1 = "";
	let winner2 = "";
	let finalGame = 0;
	const player1Name = document.getElementById('player1').value;
	const player2Name = document.getElementById('player2').value;
	const player3Name = document.getElementById('player3').value;
	const player4Name = document.getElementById('player4').value;
	const status = document.getElementById('login-status');
	let isRunning = 0;
	let playerForm = document.getElementById('playerForm');
	let gameContainer = document.getElementById('gameContainer');
	let container = document.getElementById('gameCanvas');
	let turn = localStorage.getItem('turn');
	if (!turn) {
		turn = 1;
		localStorage.setItem('turn', turn);
	}
	else {
		turn++;
		localStorage.setItem('turn', turn);
	}
	ingame();
	
	if (player1Name && player2Name && player3Name && player4Name) {
		const names = [player1Name, player2Name, player3Name, player4Name];
		const uniqueNames = new Set(names);
		if (uniqueNames.size !== names.length) {
			status.innerText = "Names must be different";
			status.style.color = "red";
			return;
		}
		playerForm.style.display = 'none';
		gameContainer.style.display = 'block';
		
		// Scroll to top
		window.scrollTo(0, 0);

		// Commencer les matchs
		match1(player1Name, player2Name);
	} else {
		status.innerText = "Fill all name fields to begin the turnament";
		status.style.color = "red";
		return;
	}

	function match1(player1Name, player2Name) {
		startGameTournament(player1Name, player2Name).then(winner => {
			winner1 = winner;
			if (localStorage.getItem('turn') != turn)
				return;
			// Attendre 3 secondes avant de lancer le match suivant
			setTimeout(() => {
				match2(document.getElementById('player3').value, document.getElementById('player4').value);
			}, 3000);
		});
	}

	function match2(player3Name, player4Name) {
		startGameTournament(player3Name, player4Name).then(winner => {
			winner2 = winner;
			if (localStorage.getItem('turn') != turn)
				return;
			setTimeout(() => {
				final(winner1, winner2);
			}, 3000);
		});
	}

	function final(winner1, winner2) {

		finalGame = 1;

		startGameTournament(winner1, winner2).then(winner => {
			winner1 = winner;
			if (localStorage.getItem('turn') != turn)
				return;
			setTimeout(() => {
				document.getElementById('gameContainer').innerHTML = '';

				const winnerMessage = document.createElement('div');
				winnerMessage.classList.add('winner-message'); 
				winnerMessage.textContent = `${winner1} won the tournament!`;

				const gameContainer = document.getElementById('gameContainer');
				gameContainer.appendChild(winnerMessage);

				// Scroll to top
				window.scrollTo(0, 0);
				let win;
				winner1 === player1Name ? win = true : win = false;
				let data = {
					'opponent': 'Tournament',
					'win': win,
				};
				(async () => {
					try {
						let csrfToken = await getCSRFToken();
						let jwtToken = localStorage.getItem('jwtToken');
						const response = await fetch('/api/tournament/', {
							method: 'POST',
							headers: {
								'Authorization': `Bearer ${jwtToken}`,
								'X-CSRFToken': csrfToken,
								'Content-Type': 'application/json',
							},
							credentials: 'include',
							body: JSON.stringify(data),
						});
	
						const respdata = await response.json();
						if (!response.ok)
							console.error(respdata.error);
					} catch (error) {
						console.error('Error during fetching:', error);
					}
				})();
				return;
			}, 3000);
			});
	}

	function startGameTournament(playername1, playername2) {
		return new Promise((resolve) => {

		container.innerHTML = '';

		// ------------------------------- //
		// ---------- COUNTDOWN ---------- //
		// ------------------------------- //
		
		// Setting up the scene, camera, lights, etc.
		
		// Define everything needed.

		// Get html/css elements
		const score1Element = document.getElementById('score1');
		const score2Element = document.getElementById('score2');
		const player1Element = document.getElementById('playerA');
		const player2Element = document.getElementById('playerB');
		const winnerElement = document.getElementById('winScreen');
		const countdownElement = document.getElementById('countdown');

		countdownElement.style.display = 'block';

		// Set playground
		const WIDTH = 1000;
		const HEIGHT = 650;
		const fieldWidth = 400, fieldHeight = 200;
		
		// Set some camera attributes.
		const VIEW_ANGLE = 45;
		const ASPECT = WIDTH / HEIGHT;
		const NEAR = 0.1;
		const FAR = 10000;
		let renderer, scene, camera, pointLightOne, pointLightTwo;

		// Set up the sphere vars
		const RADIUS = 5;
		const SEGMENTS = 16;
		const RINGS = 16;

		// Set up border vars
		const barrierThickness = 2;
		const barrierHeight = 5;
		const barrierDepth = fieldHeight;

		// Set elements of the game
		let ball, paddle1, paddle2;
		const paddleWidth = 10, paddleHeight = 10;
		const paddleDepth = 30, paddleQuality = 1;
		let paddle1DirZ = 0, paddle2DirZ = 0, paddleSpeed = 3;
		let ballDirX = -1, ballDirZ = 1, ballSpeed = 3;

		//score management
		let score1 = 0;
		let score2 = 0;
		let winner = 3;

		// Movement management
		var KEYDOWN = "KeyS", KEYUP = "KeyW", 
		KEYDOWNTWO = "ArrowDown", KEYUPTWO = "ArrowUp";

		var goUpOne = false, goDownOne = false, 
		goUpTwo = false, goDownTwo = false;

		document.addEventListener('keydown', onKeyDown);
		document.addEventListener('keyup', onKeyUp);
		
		//stop the game

		player1Element.textContent = playername1;
		player2Element.textContent = playername2;
		
		// Function to start the countdown
		function startCountdown(callback) {
			countdownElement.style.display = 'block';
			let counter = 3;
			countdownElement.textContent = `Starting in ${counter}`;

			const interval = setInterval(() => {
				counter--;
				if (counter > 0) {
					countdownElement.textContent = `Starting in ${counter}`;
				} else {
					clearInterval(interval);
					countdownElement.style.display = 'none';
					callback(); // Start the game after the countdown
				}
			}, 1000);
		}
		
		// ------------------------------- //
		// ----------- DISPLAY ----------- //
		// ------------------------------- //
		
		// Setting up : Scene, Camera, Spotlights. 
		
		// /\ -- CAMERA -- /\
		
		// Create a WebGL renderer, camera, and a scene
		renderer = new THREE.WebGLRenderer({alpha: true});
		
		camera = new THREE.PerspectiveCamera(
			VIEW_ANGLE,
			ASPECT,
			NEAR,
			FAR
		);
		
		scene = new THREE.Scene();
		
		// Add the camera to the scene.
		scene.add(camera);
		
		camera.position.set(0, 300, 350);
		camera.lookAt(scene.position);
		
		// Start the renderer.
		renderer.setSize(WIDTH, HEIGHT);
		
		// Get the DOM element to attach to
		
		// Attach the renderer-supplied DOM element.
		container.appendChild(renderer.domElement);
		
		
		// -------------------------------------------
		
		
		// /\ -- LIGHTS -- /\
		
		// create a first point light for red player
		pointLightOne = new THREE.PointLight(0xF8D898);
		
		// set its position
		pointLightOne.position.set(100, 100, 0);
		pointLightOne.intensity = 2;
		pointLightOne.distance = 0;
		
		// add to the scene
		scene.add(pointLightOne);
		
		// create a second point light for blue player
		pointLightTwo = new THREE.PointLight(0xF8D898);
		
		// set its position
		pointLightTwo.position.set(-100, 100, 0);
		pointLightTwo.intensity = 2;
		pointLightTwo.distance = 0;
		
		// add to the scene
		scene.add(pointLightTwo);
		
		
		// -------------------------------------------
		

		// -------------------------------- //
		// -------- GAME MATERIALS -------- //
		// -------------------------------- //
		
		// Setting up : Ball, Ground, GroundBorder, Paddles
		
		
		// /\ -- Ball -- /\
		
		// ball's x-direction, y-direction and speed per frame
		//create ball material
		const sphereMaterial = new THREE.MeshLambertMaterial({ color: 0x303030 });
		
		// Create a new mesh with sphere geometry
		ball = new THREE.Mesh(
			new THREE.SphereGeometry(RADIUS, SEGMENTS, RINGS),
			sphereMaterial
		);
		
		// Position the sphere on the field
		ball.position.set(0, RADIUS, 0); // Adjusted position
		
		// Finally, add the sphere to the scene.
		scene.add(ball);
		
		
		// -------------------------------------------
		
		
		// /\ -- GROUND -- /\
		
		// field variables
		
		// set up the playing surface plane 
		const planeWidth = fieldWidth, planeHeight = fieldHeight, planeQuality = 32;
		
		//create plane material
		const planeMaterial = new THREE.MeshLambertMaterial({ color: 0xF4EDDE });
		
		// create the playing surface plane
		const plane = new THREE.Mesh(
			new THREE.PlaneGeometry(planeWidth, planeHeight, planeQuality, planeQuality),
			planeMaterial
		);
		
		// Rotate the plane to be flat horizontally
		plane.rotation.x = -Math.PI / 2;
		
		// Move the plane down so it doesn't intersect the camera view
		plane.position.y = -5;
		
		scene.add(plane);
		
		
		// -------------------------------------------
		
		
		// /\ -- GROUND BORDER -- /\

		//create borders material
		const barrierMaterial = new THREE.MeshLambertMaterial({ color: 0x444444 });

		// farthest border
		// Barrière du haut
		const topBarrier = new THREE.Mesh(
			new THREE.BoxGeometry(fieldWidth, barrierHeight, barrierThickness),
			barrierMaterial
		);

		topBarrier.position.set(0, barrierHeight / 2, -fieldHeight / 2 - barrierThickness / 2);

		scene.add(topBarrier);

		// closest border
		const bottomBarrier = new THREE.Mesh(
			new THREE.BoxGeometry(fieldWidth, barrierHeight, barrierThickness),
			barrierMaterial
		);

		bottomBarrier.position.set(0, barrierHeight / 2, fieldHeight / 2 + barrierThickness / 2);

		scene.add(bottomBarrier);


		// -------------------------------------------


		// /\ -- PADDLES -- /\

		//create paddles material
		const paddle1Material = new THREE.MeshLambertMaterial({ color: 0x0000FF });
		const paddle2Material = new THREE.MeshLambertMaterial({ color: 0xFF0000 });

		// set up paddle 1
		paddle1 = new THREE.Mesh(
			new THREE.BoxGeometry(
				paddleWidth,
				paddleHeight,
				paddleDepth,
				paddleQuality,
				paddleQuality,
				paddleQuality),
				paddle1Material);
		
		// add the paddle to the scene
		scene.add(paddle1);


		// Set up the second paddle
		paddle2 = new THREE.Mesh(
			new THREE.BoxGeometry(
				paddleWidth,
				paddleHeight,
				paddleDepth,
				paddleQuality,
				paddleQuality,
				paddleQuality),
				paddle2Material);

		// Add the second paddle to the scene
		scene.add(paddle2);

		// set paddles on each side of the table
		paddle1.position.x = -fieldWidth / 2 + paddleWidth;
		paddle2.position.x = fieldWidth / 2 - paddleWidth;

		// lift paddles over playing surface
		paddle1.position.z = paddleDepth / 2;
		paddle2.position.z = paddleDepth / 2;


		// -------------------------------------------


		// -------------------------------- //
		// -------- GAME FUNCTIONS -------- //
		// -------------------------------- //

		// /\ -- Ball movement n rebound -- /\

		function ballMovement() {

			//X = left / right
			//Y = up / down (not usefull)
			//Z = farther / closer

			// update ball position over time
			ball.position.x += ballDirX * ballSpeed;
			ball.position.z += ballDirZ * ballSpeed;

			// if ball hits the top or bottom barrier
			if (ball.position.z <= -fieldHeight / 2 + RADIUS || ball.position.z >= fieldHeight / 2 - RADIUS) {
				ballDirZ = -ballDirZ;
			}

			// limit ball's z-speed to 2x the x-speed
			if (ballDirZ > ballSpeed * 2) {
				ballDirZ = ballSpeed * 2;
			} else if (ballDirZ < -ballSpeed * 2) {
				ballDirZ = -ballSpeed * 2;
			}
		}

		function paddelCollide() {
			// Paddle1 (left)
			if (ball.position.x - RADIUS <= paddle1.position.x + paddleWidth / 2 
				&& ball.position.x + RADIUS >= paddle1.position.x - paddleWidth / 2) {
				if (ball.position.z <= paddle1.position.z + paddleDepth / 2 
					&& ball.position.z >= paddle1.position.z - paddleDepth / 2) {
					if (ballDirX < 0) {
						ballDirX = -ballDirX;
						// Calculer la nouvelle direction Z
						let impactPoint = (ball.position.z - paddle1.position.z) / (paddleDepth / 2);
						ballDirZ = impactPoint * ballSpeed / 1.5;
					}
				}
			}
		
			// Paddle2 (right)
			if (ball.position.x + RADIUS >= paddle2.position.x - paddleWidth / 2 
				&& ball.position.x - RADIUS <= paddle2.position.x + paddleWidth / 2) {
				if (ball.position.z <= paddle2.position.z + paddleDepth / 2 
					&& ball.position.z >= paddle2.position.z - paddleDepth / 2) {
					if (ballDirX > 0) {
						ballDirX = -ballDirX;
						// Calculer la nouvelle direction Z
						let impactPoint = (ball.position.z - paddle2.position.z) / (paddleDepth / 2);
						ballDirZ = impactPoint * ballSpeed / 1.5;
					}
				}
			}
		}
		

		// -------------------------------------------


		// /\ -- Paddle Management -- /\


		function onKeyDown(event) {

			if (event.code == KEYDOWN) {
				goDownOne = true;
			}
			if (event.code == KEYUP) {
				goUpOne = true;
			} 

			if (event.code == KEYDOWNTWO) {
				goDownTwo = true;
			}
			if (event.code == KEYUPTWO) {
				goUpTwo = true;
			} 
		}

		function onKeyUp(event) {

			if (event.code == KEYDOWN) {
				goDownOne = false;
			}
			if (event.code == KEYUP) {
				goUpOne = false;
			} 

			if (event.code == KEYDOWNTWO) {
				goDownTwo = false;
			}
			if (event.code == KEYUPTWO) {
				goUpTwo = false;
			} 
		}

		function playersMovement() {

			if (goUpOne && paddle1.position.z > -fieldHeight / 2 + paddleDepth / 2 + 2) {
				paddle1.position.z -= paddleSpeed;
			}
			if (goDownOne && paddle1.position.z < fieldHeight / 2 - paddleDepth / 2 - 2) {
				paddle1.position.z += paddleSpeed;
			}

			if (goUpTwo && paddle2.position.z > -fieldHeight / 2 + paddleDepth / 2 + 2) {
				paddle2.position.z -= paddleSpeed;
			}
			if (goDownTwo && paddle2.position.z < fieldHeight / 2 - paddleDepth / 2 - 2) {
				paddle2.position.z += paddleSpeed;
			}

		}


		// -------------------------------------------


		// /\ -- Score Management -- /\

		function goalManagement() {

			if (ball.position.x >= paddle2.position.x + paddleWidth / 2)
			{
				score1 += 1;
				updateScores();
				resetBall();
			}

			if (ball.position.x <= paddle1.position.x - paddleWidth / 2)
			{
				score2 += 1;
				updateScores();
				resetBall();
			}
		}

		function updateScores() {

			if (score1Element && score2Element) {
				score1Element.textContent = score1;
				score2Element.textContent = score2;
			}

		}

		function resetBall() {
			ballSpeed = 0;
			ballDirZ = 0;
			ball.position.set(0, RADIUS, 0);

			// Reset paddle positions
			paddle1.position.z = paddleDepth / 2;
			paddle2.position.z = paddleDepth / 2;
			paddle1DirZ = 0;
			paddle2DirZ = 0;

			setTimeout(() => {
				ballDirX = (score1 > score2) ? -1 : 1;
				ballDirZ = Math.random() * 2 - 1;
				ballSpeed = 3;
			}, 2000); 
		}

		function scoreCheck() {
			if (score1 >= winner) {
				ballSpeed = 0;
				isRunning = 1;
			} else if (score2 >= winner) {
				ballSpeed = 0;
				isRunning = 2;
			}
		}

		function resetGame() {
			score1 = 0;
			score2 = 0;
			updateScores();
		
			ball.position.set(0, RADIUS, 0);
			ballSpeed = 3;
			ballDirX = -1;
			ballDirZ = 1;
		
			paddle1.position.z = paddleDepth / 2;
			paddle2.position.z = paddleDepth / 2;
		
			isRunning = 0;
		
			winnerElement.innerText = '';
		}

		function update() {
			// Draw!
			renderer.render(scene, camera);
			
			ballMovement();
			playersMovement();
			paddelCollide();
			goalManagement();
			scoreCheck();
			if (localStorage.getItem('turn') != turn)
				return;
			if (isRunning != 0) {
				ballSpeed = 0;
				ball.position.set(0, RADIUS, 0);
				renderer.render(scene, camera);

				if (isRunning == 1) {
					winnerElement.innerText = `${playername1} Wins !`;
					resolve(playername1);
				} else if (isRunning == 2) {
					winnerElement.innerText = `${playername2} Wins !`;
					resolve(playername2);
				}
				if (finalGame == 0)
					setTimeout(resetGame, 3000); // Wait for 2 seconds and reset the game

				return;
			}
			requestAnimationFrame(update);
		}
		
		
		// Start the countdown and then start the game
		startCountdown(() => {
			update();
		});
	})};
}