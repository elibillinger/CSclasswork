/// @description 

var aX = 0;
var aY = 0;

//TODO Left key rotate image left
if(keyboard_check(vk_left)){
	image_angle += 5;
}
if(keyboard_check(vk_right)){
	image_angle -= 5;
}
//TODO right key roate image right
//TODO up arrow add thrust
	//add acceleration
	//flicker image
	//play thrust sound
	
// not thrust
	//stop sound and flicker
	

// call update object script
updateObject(aX,aY);

//TODO get back distance to the sun if too close destroy astronaut play sound