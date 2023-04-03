/// @description 

event_inherited();

// Make enemy move, switching directions every 25 pixels on either side.
if (global.game_state == states.playing) {
	if (x <= start_x || x >= end_x) {
		dir *= -1;
	}
	x += spd * dir;
}
