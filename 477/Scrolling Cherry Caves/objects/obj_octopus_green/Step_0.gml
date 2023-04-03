/// @description Control movement

if (global.game_state == states.playing) {
	if (place_meeting(x, y, obj_block)) {
		dir *= -1;
		image_xscale *= -1;
	}
	
	x += spd * dir;
}