/// @description Move side to side

if (global.game_state == states.playing) {
	if (place_meeting(x, y, obj_block)) {
		dir *= -1;
	}
	global.mov_platform_dir = dir;
	x += spd * dir;
}