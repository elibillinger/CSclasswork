function updateObject(arg0,arg1){
	var aX = arg0;
	var aY = arg1;
	
	//compute the acceleartion due to gravity from the sun
	//TODO calculate vector from sun to the astronaut
	
	//TODO get the magnitude of that vector
	//may need to protect from dividing by 0
	//know if too close to sun
	
	
	//TODO normalize the direction vector
	
	//TODO add the gravitational acceleration to the astronaut acceleration 
		//use GRAV const
	
	
	//update velocity based on acceleration
	vX += aX;
	vY += aY;
	
	//update position based on velocity
	x += vX;
	y += vY;
	
	//Wrap the object around in the x direction
	if(x < 0) {
		x += room_width;
	} else if(x > room_width) {
		x -= room_width;
	}
	//Wrap the object around in the y direction
	if(y < 0) {
		y += room_height;
	} else if(y > room_height) {
		y -= room_height;
	}
	
	//return magnitude so astronaut can destroy itself
}