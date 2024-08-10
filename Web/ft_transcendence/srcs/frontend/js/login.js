async function handleLogin() {
	const loginForm = document.getElementById('loginForm');
	const loginStatus = document.getElementById('login-status');
	const submitButton = loginForm.querySelector('[type="submit"]');
	
	loginForm.addEventListener('submit', async (e) => {
		e.preventDefault();
		
		if (submitButton)
			submitButton.disabled = true;

		let csrfToken = await getCSRFToken();

		const formData = new FormData(loginForm);
		formData.append('csrfmiddlewaretoken', csrfToken); 
					
		try {
			const response = await fetch('/api/login/', {
				method: 'POST',
				credentials: 'include',
				body: formData
			});

			const data = await response.json();
			
			if (response.ok) {
				if (data.message) {
					if (data.message === "Login successful") {
						loginStatus.textContent = data.message;
						loginStatus.style.color = "green";
						const jwtToken = data.jwt_token;
						if (jwtToken)
							localStorage.setItem('jwtToken', jwtToken);
						localStorage.setItem('loggedIn', 'true');
						if (submitButton)
							submitButton.disabled = false;
						updateNav();
						window.history.pushState({}, "", '/home');
						await handleLocation();
					} else if (data.message === "OTP sent to email") {
						if (data.username) 
							localStorage.setItem('username', data.username);
						window.history.pushState({}, "", '/2fa');
						await handleLocation();
					}
				}
			}
			else {
				if (data.hasOwnProperty('error') && data.error === "Invalid login credentials") {
					loginStatus.textContent = data.error;
					loginStatus.style.color = "red";
				} else {
					loginStatus.textContent = "Login failed. Please check your credentials.";
					loginStatus.style.color = "red";
				}
				if (submitButton)
					submitButton.disabled = false;
			}
		} catch (error) {
			console.error("Error logging in:", error);
			loginStatus.textContent = "Error logging in. Please try again later.";
			loginStatus.style.color = "red";

			if (submitButton)
				submitButton.disabled = false;
		}
	});
}

