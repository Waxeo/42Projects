async function uploadImage() {
	try{
		const form = document.getElementById('uploadForm');
		const formData = new FormData(form);
		let csrfToken = await getCSRFToken();
		let jwtToken = localStorage.getItem('jwtToken')
		if (!jwtToken) {
			throw new Error('JWT token not found.');
		}
		const response = await fetch('/api/upload/', {
			method: 'POST',
			headers: {
				'Authorization': `Bearer ${jwtToken}`,
				'X-CSRFToken': csrfToken
			},
			body: formData
		})
		const data = await response.json();
		if(response.ok){
			console.log('Image uploaded successfully:', data.image_url);
			const profil_image = document.getElementById('profile-image');
			profil_image.src = `"${data.profil_image}" `;
			window.history.pushState({}, "", '/profile');
			await handleLocation();
		} else {
			console.error("Error uploading image");
		}
	} catch (error) {
        console.error('Error during upload image:', error);
	}
}