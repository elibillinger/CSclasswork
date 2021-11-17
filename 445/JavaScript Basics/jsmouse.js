function happyFace(){
	var canvas = document.getElementById("myCanvas");
	var ctx = canvas.getContext("2d");
	ctx.beginPath();
	ctx.arc(200, 200, 100, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#339FFF"
	ctx.fill();
	// eyes
	ctx.beginPath();
	ctx.arc(165, 175, 15, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#000000"
	ctx.fill();
	// eyes
	ctx.beginPath();
	ctx.arc(235, 175, 15, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#000000"
	ctx.fill();

	ctx.beginPath();
	ctx.arc(200, 230, 50, 0, Math.PI,false);
	ctx.stroke();
}
function sadFace(){
	var canvas = document.getElementById("myCanvas");
	var ctx = canvas.getContext("2d");
	ctx.beginPath();
	ctx.arc(200, 200, 100, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#339FFF"
	ctx.fill();
	// eyes
	ctx.beginPath();
	ctx.arc(165, 175, 15, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#000000"
	ctx.fill();
	// eyes
	ctx.beginPath();
	ctx.arc(235, 175, 15, 0, 2 * Math.PI);
	ctx.stroke();
	ctx.fillStyle = "#000000"
	ctx.fill();

	ctx.beginPath();
	ctx.arc(200, 250, 50, Math.PI, 2*Math.PI,false);
	ctx.stroke();
}
happyFace();


var button = document.getElementById("btn");
btn.addEventListener("click", ()=>{
	 if (btn.value=="Make Me Sad")
	 {
	 	btn.value = "Make Me Happy";
	 	var canvas = document.getElementById("myCanvas");
	 	var ctx = canvas.getContext("2d");
	 	ctx.clearRect(0,0,ctx.width,ctx.height);
	 	sadFace();
	 } 
    else{
    	btn.value = "Make Me Sad";
    	var canvas = document.getElementById("myCanvas");
    	var ctx = canvas.getContext("2d");
    	ctx.clearRect(0,0,ctx.width,ctx.height);
    	happyFace();
    } 
});

var canvas = document.getElementById("myCanvas");
canvas.addEventListener("mousedown", getPosition, false);

function getPosition(event){
	var x = event.x;
	var y = event.y;
	var canvas = document.getElementById("myCanvas");
	var ctx = canvas.getContext("2d");
	x -= canvas.offsetLeft;
    y -= canvas.offsetTop;
    if(x >= 100 && x <= 300 && y >= 100 && y <= 300){
    	if (btn.value=="Make Me Sad") {
	 	btn.value = "Make Me Happy";
	 	ctx.clearRect(0,0,ctx.width,ctx.height);
	 	sadFace();
	 } 
    else{
    	btn.value = "Make Me Sad";
    	ctx.clearRect(0,0,ctx.width,ctx.height);
    	happyFace();
    } 
    }
}