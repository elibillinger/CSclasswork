// move spd*dir, reversing dir when a boundary is hit (the 25-pixel artifical boundary)
if(global.game_state == states.playing) {
	if ( x <= start_x or x >= end_x){
		dir *= -1;
	}
	x += spd * dir;
}

if(hp <= 0) {
	instance_destroy(); //this destroys self and triggers destroy event
	score += 10;
}