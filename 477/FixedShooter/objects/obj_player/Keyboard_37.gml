///@description Move Left

//while holding down left arrow player will move left

if (global.game_state == states.playing && x > 0 + sprite_width / 2) {
	x -= spd;
}