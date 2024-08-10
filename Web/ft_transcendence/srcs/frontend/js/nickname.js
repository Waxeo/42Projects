async function handleNickname() {
	const loginForm = document.getElementById('nicknameForm');
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
			let jwtToken = localStorage.getItem('jwtToken');
			if (!jwtToken) {
				throw new Error('JWT token not found.');
			}
			const response = await fetch('/api/nickname/', {
				method: 'POST',
				credentials: 'include',
				headers: {
					'Authorization': `Bearer ${jwtToken}`,
				},
				body: formData
			});

			const data = await response.json();
			
			if (response.ok) {
				if (data.message) {
					if (data.message === "Update successful") {
						loginStatus.textContent = data.message;
						loginStatus.style.color = "green";
						if (submitButton)
							submitButton.disabled = false;
						window.history.pushState({}, "", '/profile');
						await handleLocation();
					}
				}
			}
			else {
				if (data.hasOwnProperty('error')) {
					loginStatus.textContent = data.error;
					loginStatus.style.color = "red";
				} else {
					loginStatus.textContent = "Update failed. Please check input.";
					loginStatus.style.color = "red";
				}
				if (submitButton)
					submitButton.disabled = false;
			}
		} catch (error) {
			console.error("Error updating:", error);
			loginStatus.textContent = "Error updating. Please try again later.";
			loginStatus.style.color = "red";

			if (submitButton)
				submitButton.disabled = false;
		}
	});
}