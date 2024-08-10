async function handleOauth() {
	const params = new URLSearchParams(window.location.search);
    const jwtToken = params.get('jwtToken');
    const username = params.get('username');
    const is_2fa = params.get('2fa');

    if (is_2fa === 'True') {
       localStorage.setItem('username', username);
       if (jwtToken)
            localStorage.setItem('jwtToken', jwtToken);
       window.location.href = "/2fa";
       await handleLocation();
    }
    else {
        if (jwtToken)
            localStorage.setItem('jwtToken', jwtToken);
        localStorage.setItem('loggedIn', 'true');
        window.location.href = "/home";
        await handleLocation();
    }
}