// Set up Motion

// have the bullet be pointing towards the mouse position
direction = point_direction(x,y,mouse_x,mouse_y);
direction = direction + random_range(-4,4);
// how many pixels the bullet will move per frame 
speed = 16;
// draw the bullet facing the direction of the mouse
image_angle = direction;