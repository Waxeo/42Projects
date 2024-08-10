async function not_log() {
	window.history.pushState({}, "", '/login');
	await handleLocation();
}