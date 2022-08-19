//Get a reference of the project image that we're using
const projImage = document.getElementByID("project-img");

//this event listener looks for any click functionality on the image. If the image is clicked, 
//we're gonna hide it, and if its clicked again, then it will show

projImage.addEventListener("click", function ShowProjectText() {
	const projText = document.getElementByID("project-text");
	if (projText.style.visibility == "hidden") {
		projText.style.visibility = "visible";
	} else {
		projText.style.visibility = "hidden";
	}
})

//Get a reference to the about-me image that we're using
cons aboutMeImage = document.getElementById("about-me-img");

//This event listener looks for any mouse over on the image
//If hovered over, it will do a custom flip
AboutMeImage.addEventListener("mouseover", function doaFlip() {
	if (aboutmeImage.style.transform ==  "rotate(360deg)") {
		aboutMeStyle.transform = "rotate(0deg)";
	} else {
		aboutMeImage.style.transform = "rotate(360deg)";
	}
})