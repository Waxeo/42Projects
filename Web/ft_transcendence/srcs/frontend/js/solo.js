function startGameSolo() {
	
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
	let turn = localStorage.getItem('turn');
	if (!turn) {
		turn = 1;
		localStorage.setItem('turn', turn);
	}
	else {
		turn++;
		localStorage.setItem('turn', turn);
	}

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
	let player1 = "Player";
	let player2 = "CPU";
	let winner = 2;

	// Movement management
	var KEYDOWN = "KeyS", KEYUP = "KeyW", 
	KEYDOWNTWO = "ArrowDown", KEYUPTWO = "ArrowUp";

	var goUpOne = false, goDownOne = false, 
	goUpTwo = false, goDownTwo = false;

	document.addEventListener('keydown', onKeyDown);
	document.addEventListener('keyup', onKeyUp);
	
	//stop the game
	var isRunning = 0;

	player1Element.textContent = player1;
	player2Element.textContent = player2;
	
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
	const container = document.getElementById('gameCanvas');
	
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

	//the comments in moving functions are for multiPlayers mode
	//bot function will control paddle2 in training mode

	function onKeyDown(event) {

		if (event.code == KEYDOWN) {
			goDownOne = true;
		}
		if (event.code == KEYUP) {
			goUpOne = true;
		} 

		// if (event.code == KEYDOWNTWO) {
		// 	goDownTwo = true;
		// }
		// if (event.code == KEYUPTWO) {
		// 	goUpTwo = true;
		// } 
	}

	function onKeyUp(event) {

		if (event.code == KEYDOWN) {
			goDownOne = false;
		}
		if (event.code == KEYUP) {
			goUpOne = false;
		} 

		// if (event.code == KEYDOWNTWO) {
		// 	goDownTwo = false;
		// }
		// if (event.code == KEYUPTWO) {
		// 	goUpTwo = false;
		// } 
	}

	function playersMovement() {

		if (goUpOne && paddle1.position.z > -fieldHeight / 2 + paddleDepth / 2 + 2) {
			paddle1.position.z -= paddleSpeed;
		}
		if (goDownOne && paddle1.position.z < fieldHeight / 2 - paddleDepth / 2 - 2) {
			paddle1.position.z += paddleSpeed;
		}

		// if (goUpTwo && paddle2.position.z > -fieldHeight / 2 + paddleDepth / 2 + 2) {
		// 	paddle2.position.z -= paddleSpeed;
		// }
		// if (goDownTwo && paddle2.position.z < fieldHeight / 2 - paddleDepth / 2 - 2) {
		// 	paddle2.position.z += paddleSpeed;
		// }

	}

	function moveAI() {

		if (ballDirX < 0) {

			if (paddle2.position.z < 0)
				paddle2.position.z += paddleSpeed;

			else if (paddle2.position.z > 0)
				paddle2.position.z -= paddleSpeed;

		}
		if (ballDirX > 0) {

		if (ball.position.z <= paddle2.position.z - paddleDepth / 2)
			paddle2.position.z -= paddleSpeed;

		if (ball.position.z >= paddle2.position.z + paddleDepth / 2)
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

		if (score1 >= winner)
		{
			ballSpeed = 0;
			isRunning = 1;

		}
		else if (score2 >= winner)
		{
			ballSpeed = 0;
			isRunning = 2;
		}
	}

	function update() {
		// Draw!
		renderer.render(scene, camera);
		
		ballMovement();
		playersMovement();
		moveAI();
		paddelCollide();
		goalManagement();
		scoreCheck();
		if (localStorage.getItem('turn') != turn)
			return;

		if (isRunning != 0) {
			let win;
			ballSpeed = 0;
			ball.position.set(0, RADIUS, 0);
			renderer.render(scene, camera);
			if (isRunning == 1) {
				winnerElement.textContent = `Player Wins !`;
				win = true;
			}
			else if (isRunning == 2) {
				winnerElement.textContent = `CPU Wins !`;
				win = false;
			}
			
			let data = {
				'opponent': 'CPU',
				'win': win,
				'my_score': score1,
				'opponent_score': score2,
			};
			
			(async () => {
				try {
					let csrfToken = await getCSRFToken();
					let jwtToken = localStorage.getItem('jwtToken');
					const response = await fetch('/api/game_end/', {
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
		}
		requestAnimationFrame(update);
	}

	// Start the countdown and then start the game
	startCountdown(() => {
		update();
	});
}
