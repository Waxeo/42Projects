async function not_ingame(){
	const response = await fetch('/api/not_ingame');
	if (response.ok) {
		console.log("Fetch ok");
		let turn = localStorage.getItem('turn');
		if (turn) {
			turn++;
			localStorage.setItem('turn', turn);
		}
	}
	else
		console.error("Failed fetching");
}