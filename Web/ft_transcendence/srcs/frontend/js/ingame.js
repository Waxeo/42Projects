async function ingame(){
	const response = await fetch('/api/ingame');
	if (response.ok)
		console.log("Fetch ok");
	else
		console.error("Failed fetching");
}