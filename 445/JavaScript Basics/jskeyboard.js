var img = document.getElementById("car");
img.style.visibility = "hidden";
var x = 10;
var y = 10;

function drawImage(){
    var canvas = document.getElementById("myCanvas");
    var ctx = canvas.getContext("2d");
    ctx.clearRect(0,0,400,400);
    ctx.drawImage(img, x, y,70,60);
}

function onkeydown(e) {
  if(e.keyCode==39 && x < 330) {x++;} //right arrow
  else if(e.keyCode==37 && x > 0) {x--;} //left arrow
  else if(e.keyCode==38 && y > -20) {y--;} //up arrow
  else if(e.keyCode==40 && y < 360) {y++;} //down arrow
  drawImage();
}
 drawImage();
window.addEventListener("keydown", onkeydown);