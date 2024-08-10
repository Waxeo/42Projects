
async function handle2fa() {
	const loginForm = document.getElementById('2fa_form');
	const loginStatus = document.getElementById('login-status');
	const submitButton = loginForm.querySelector('[type="submit"]');

	loginForm.addEventListener('submit', async (e) => {
		e.preventDefault();
		
		if (submitButton)
			submitButton.disabled = true;

		let csrfToken = await getCSRFToken();
        let username = localStorage.getItem('username');
		const formData = new FormData(loginForm);
        formData.append('username', username);
		formData.append('csrfmiddlewaretoken', csrfToken); 
					
		try {
			const response = await fetch('/api/check_2fa/', {
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
					}
				}
			}
			else {
				if (data.hasOwnProperty('error') && data.error === "Invalid OTP") {
					loginStatus.textContent = data.error;
					loginStatus.style.color = "red";
				} else {
					loginStatus.textContent = "OTP check failed. Please check your otp.";
					loginStatus.style.color = "red";
				}
				if (submitButton)
					submitButton.disabled = false;
			}
		} catch (error) {
			console.error("Error checking otp:", error);
			loginStatus.textContent = "Error checking otp. Please try again later.";
			loginStatus.style.color = "red";

			if (submitButton)
				submitButton.disabled = false;
		}
	});
}

