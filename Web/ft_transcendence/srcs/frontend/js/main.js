const routes = {
    404: "../templates/404.html",
    "/": "../templates/home.html",
    "/home": "../templates/home.html",
    "/login": "../templates/login.html",
    "/2fa": "../templates/2fa.html",
    "/register": "../templates/register.html",
    "/play": "../templates/play.html",
    "/return": "../templates/home.html",
    "/logout": "../templates/logout.html",
    "/profile": "../templates/profile.html",
    "/solo": "../templates/games.html",
    "/multi": "../templates/games.html",
    "/tournament": "../templates/tournament.html",
    "/nickname": "../templates/nickname.html",
}

const route = (event) => {
    event = event || window.event;
    event.preventDefault();
    window.history.pushState({}, "", event.target.href);
    handleLocation(); 
};

async function getCSRFToken() {
    return fetch('/api/get-csrf-token/', {
        method: 'GET',
        credentials: 'include'
    })
    .then(response => response.json())
    .then(data => data.csrfToken)
    .catch(error => {
        console.error('Error while fetching CSRF token:', error);
        return null;
    });
}

async function updateNav() {
    let loggedIn = localStorage.getItem('loggedIn') === 'true';

    const navBar = document.getElementById('navbar');

    navBar.innerHTML = '';

    const menuNav = loggedIn || localStorage.getItem('loggedIn') === 'true' ?
    ['Home', 'Play', 'Profile', 'Logout'] :
    ['Home', 'Login'];

    menuNav.forEach(item => {
        const a = document.createElement('a');

        a.classList.add('nav-link', 'active');
        a.href = `/${item.toLowerCase()}`;
        a.textContent = item;

        a.onclick = (event) => route(event);
        navBar.appendChild(a);
    });
}

const handleLocation = async ()=> {
    let path = window.location.pathname;
    const route = routes[path] || routes[404];
    const html = await fetch(route).then((data) => data.text());
    document.getElementById("app").innerHTML = html;

    switch(path) {
        case '/home':
            await not_ingame();
            break;
        case '/login':
            if (localStorage.getItem("loggedIn") === "true") {
                await not_ingame();
				log();
				break;
			}
            await handleLogin();
            break;
        case '/2fa':
            await handle2fa();
            break;
        case '/return':
            await handleOauth();
            break;
        case '/logout':
            await not_ingame();
            await handleLogout();
            break;
        case '/register':
            if (localStorage.getItem("loggedIn") === "true") {
                await not_ingame();
				log();
				break;
			}
            await handleRegister();
            break;
		case '/play':
			if (localStorage.getItem("loggedIn") !== "true") {
				not_log();
				break;
			}
            await not_ingame();
			break;
        case '/profile':
            if (localStorage.getItem("loggedIn") !== "true"){
                not_log();
                break;
            }
            await not_ingame();
            await handleProfile();
            break;  
		case '/solo':
			if (localStorage.getItem("loggedIn") !== "true"){
                not_log();
				break;
			}
            await ingame();
			startGameSolo();
			break;
		case '/multi':
			if (localStorage.getItem("loggedIn") !== "true"){
				not_log();
				break;
			}
            await ingame();
			startGameMulti();
			break;
		case '/tournament':
			if (localStorage.getItem("loggedIn") !== "true"){
				not_log();
				break;
			}
			break;
        case '/nickname':
            if (localStorage.getItem("loggedIn") !== "true"){
				not_log();
				break;
			}
            handleNickname();
            break; 
        default:
            break;
    }
};

updateNav();
handleLocation();
window.onpopstate = () => {
    handleLocation();
}
window.route = route;

