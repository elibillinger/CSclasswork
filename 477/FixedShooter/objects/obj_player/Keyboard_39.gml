///@description Move Right

//while holding down right arrow player will move right
if (global.game_state == states.playing && x < room_width - sprite_width/2) {
	x += spd;
}