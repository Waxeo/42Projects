async function not_log() {
	window.history.pushState({}, "", '/home');
	await handleLocation();
}