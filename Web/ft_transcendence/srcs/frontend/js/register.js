async function handleRegister() {
	const registerForm = document.getElementById('registerForm');
	const registerStatus = document.getElementById('register-status');
	const submitButton = registerForm.querySelector('[type="submit"]');

	registerForm.addEventListener('submit', async (e) => {
		e.preventDefault();

		if (submitButton)
			submitButton.disabled = true;

		let csrfToken = await getCSRFToken();

		const formData = new FormData(registerForm);
		formData.append('csrfmiddlewaretoken', csrfToken);

		try {
			const response = await fetch('/api/register/', {
				method: 'POST',
				credentials: 'include',
				body: formData
			});

			const data = await response.json();

			if (response.ok) {
				if (data.message) {
					registerStatus.textContent = data.message;
					registerStatus.style.color = 'green';
					if (submitButton)
						submitButton.disabled = false;
					window.history.pushState({}, "", '/login');
					await handleLocation();
				}
			} else {
				if (data.hasOwnProperty('error') && (data.error === "Username already used" || data.error === "Email already used" || data.error === "Passwords do not match") || data.error.substring(0, 13) === "Your password" || data.error === "Email is not valid") {
					registerStatus.textContent = data.error;
					registerStatus.style.color = "red";
				} else {
					registerStatus.textContent = "An error occured during registration";
					registerStatus.style.color = "red";
				}
				if (submitButton)
                    submitButton.disabled = false;
			}
		} catch (error) {
			console.error("Error during registration:", error);
            registerStatus.textContent = "An error occured during registration. Please try again later.";
			registerStatus.style.color = "red";

			if (submitButton)
                submitButton.disabled = false;
		}
	})
}