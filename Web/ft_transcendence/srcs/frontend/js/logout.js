async function handleLogout() {
	let csrfToken = await getCSRFToken();

	try{
		let jwtToken = localStorage.getItem('jwtToken');
		if (!jwtToken) {
			throw new Error('JWT token not found.');
		}
		const response = await fetch('/api/logout/', {
            method: 'POST',
            headers: {
                'Authorization': `Bearer ${jwtToken}`,
                'X-CSRFToken': csrfToken
            },
            credentials: 'include'
        });
		if (response.ok) {
            const result = await response.json();
            console.log(result.message);
			if (localStorage.getItem('jwtToken'))
            	localStorage.removeItem('jwtToken');
            localStorage.setItem('loggedIn', 'false');
            updateNav();
            window.history.pushState({}, "", '/home');
            await handleLocation();
        } else {
            console.error('Logout failed:', response.statusText);
        }
    } catch (error) {
        console.error('Error during logout:', error);
    }
}