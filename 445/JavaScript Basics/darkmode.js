function dark(){
	var text = document.getElementById("toggle");
	var article = document.getElementById("art");
	var footer = document.getElementById("foot");
	var nav = document.getElementById("nav");
	text.innerHTML = "Enable Light Mode";
	document.body.style.backgroundColor = "black";
	document.body.style.color = "white";
	art.style.backgroundColor = "black";
	art.style.color = "white";
	foot.style.backgroundColor = "darkgray";
	nav.style.backgroundColor = "darkgray";
	nav.style.color = "black";
}

function light(){
	var text = document.getElementById("toggle");
	var article = document.getElementById("art");
	var footer = document.getElementById("foot");
	var nav = document.getElementById("nav");
	text.innerHTML = "Enable Dark Mode";
	document.body.style.backgroundColor = "lightskyblue";
	document.body.style.color = "black";
	art.style.backgroundColor = "whitesmoke";
	art.style.color = "black";
	foot.style.backgroundColor = "powderblue";
	nav.style.backgroundColor = "darkblue";
	nav.style.color = "steelblue";
}


document.addEventListener('DOMContentLoaded',function() {
	var checkbox = document.querySelector('input[type="checkbox"]');
	var text = document.getElementById("toggle");
	var article = document.getElementById("art");
	if (typeof(Storage) !== "undefined") {
		if(sessionStorage.checked == "true"){
			dark();
			checkbox.checked = true;
		} else {
			light();
			checkbox.checked = false;
		}
	}

	checkbox.addEventListener('change',function() {

		if(checkbox.checked){
			dark();
			sessionStorage.setItem("checked","true");

		} else {
			light();
			sessionStorage.setItem("checked","false");
		}
	});
});

