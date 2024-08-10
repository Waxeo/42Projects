async function handleProfile() {
    let csrfToken = await getCSRFToken();
    const params = new URLSearchParams(window.location.search);
    const username = params.get('username');
    let response;
    
    if (username){
        send_data = {username: username};
        try{
            let jwtToken = localStorage.getItem('jwtToken');
            if (!jwtToken) {
                throw new Error('JWT token not found.');
            }
            response = await fetch('/api/profile/', {
                method: 'POST',
                headers: {
                    'Authorization': `Bearer ${jwtToken}`,
                    'X-CSRFToken': csrfToken,
                    'Content-Type': 'application/json'
                },
                credentials: 'include',
                body: JSON.stringify(send_data),

            });
        } catch (error) {
            console.error('Error during fetching:', error);
        }
    } else {
        response = await fetch('/api/profile/')
    }
    if (response.ok) {
        const responseData = await response.json();
        const data = responseData.data;
        if (data.message){
            if (data.message === "Other profile"){
                const edit_button = document.getElementById('edit-btn');
                const form = document.getElementById('uploadForm');
                const friendForm = document.getElementById('friend-form');
                friendForm.remove();
                form.remove();
                edit_button.remove();
            }
        }
        const nickname = document.getElementById('nickname');
        const email = document.getElementById('email');
        const profil_image = document.getElementById('profile-image');
        
        const total_games = document.getElementById('total-games');
        const won_games = document.getElementById('won-games');
        const lost_games = document.getElementById('lost-games');
        const ratio_games = document.getElementById('ratio-games');

        const history = document.getElementById('history');
        const friends = document.getElementById('friends');



        nickname.innerText = data.nickname;
        email.innerText = data.email;
        profil_image.src = data.profil_image;

        total_games.innerText = data.number_of_game;
        won_games.innerText = data.number_of_win;
        lost_games.innerText = data.number_of_defeat;
        ratio_games.innerText = data.win_percentage + '%';

        data.games.forEach(item => {
            const li = document.createElement('li');
            const type = document.createElement('span');
            const score = document.createElement('span');
            const date = document.createElement('span');
            
            if (item.opponent === "Tournament"){
                type.textContent = `${item['opponent']}`;
                date.textContent = `${item['date']}`;
                li.appendChild(type);
                li.appendChild(date);
            } else {
                score.textContent = `${item['my_score']} - ${item['opponent_score']}`;
                type.textContent = `VS ${item['opponent']}`;
                date.textContent = `${item['date']}`;
                li.appendChild(type);
                li.appendChild(score);
                li.appendChild(date);
            }
            li.style.display = 'flex';
            li.style.justifyContent = 'space-between';
            li.classList.add("list-group-item");
            if (item.win)
                li.classList.add("list-group-item-success")
            else
                li.classList.add("list-group-item-danger");
            history.appendChild(li);
        });

        data.friends.forEach(item => {
            const lis = document.createElement('li');
            const div = document.createElement('div');
            const circle = document.createElement('div');
            const img = document.createElement('img');
            const a = document.createElement('a');
            
            img.src = `${item["profil_image"]}`;
            img.alt = `${item["nickname"]} profile picture`;
            img.classList.add("rounded-circle");
            img.classList.add("img-fluid");

            circle.classList.add("status-circle");
            if (item.ingame)
                circle.style.backgroundColor = "red";
            else if (item.online)
                circle.style.backgroundColor = "green";
            else if (!item.online)
                circle.style.backgroundColor = "grey";
            


            div.classList.add("icon-container");
            div.style.display = "flex";
            div.style.alignItems = "center";
            div.appendChild(img);
            div.appendChild(circle);
            div.appendChild(a);

            a.innerText = `${item["nickname"]}`;
            a.href = `/profile?username=${item["username"]}`;
            a.classList.add("link-dark");
            a.classList.add("mb-1");
            a.style.marginLeft = "1rem";
            a.style.fontSize = "1.1rem";
            a.style.textDecoration = "none";
            a.onclick = (event) => route(event); 

            lis.classList.add("list-group-item");
            lis.classList.add("border-0");
            lis.appendChild(div);

            friends.appendChild(lis);

        });
    }

    const friendForm = document.getElementById('friend-form');
	const friendStatus = document.getElementById('login-status');
	const submitButton = friendForm.querySelector('[type="submit"]');

	friendForm.addEventListener('submit', async (e) => {
		e.preventDefault();

		if (submitButton)
			submitButton.disabled = true;

		let csrfToken = await getCSRFToken();
        let jwtToken = localStorage.getItem('jwtToken');
		if (!jwtToken) {
			throw new Error('JWT token not found.');
		}

		const formData = new FormData(friendForm);
		formData.append('csrfmiddlewaretoken', csrfToken);

		try {
			const response = await fetch('/api/addfriend/', {
				method: 'POST',
                headers: {
                    'Authorization': `Bearer ${jwtToken}`,
                },
				credentials: 'include',
				body: formData
			});

			const data = await response.json();

			if (response.ok) {
				if (data.message) {
					friendStatus.textContent = data.message;
					friendStatus.style.color = 'green';
					if (submitButton)
						submitButton.disabled = false;
					window.history.pushState({}, "", '/profile');
					await handleLocation();
				}
			} else {
				if (data.hasOwnProperty('error') && (data.error === "You cannot add yourself as a friend." || data.error === "User does not exist.")){
					friendStatus.textContent = data.error;
					friendStatus.style.color = "red";
				} else {
					friendStatus.textContent = "An error occured during friend request";
					friendStatus.style.color = "red";
				}
				if (submitButton)
                    submitButton.disabled = false;
			}
		} catch (error) {
			console.error("Error during friend request:", error);
            friendStatus.textContent = "An error occured during friend request. Please try again later.";
			friendStatus.style.color = "red";

			if (submitButton)
                submitButton.disabled = false;
		}
	})
}