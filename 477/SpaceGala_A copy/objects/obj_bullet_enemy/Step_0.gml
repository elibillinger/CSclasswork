/// @description 

// Bullet only moves if we are in playing state.
if (global.game_state == states.playing) {
	speed = spd;
} else {
	speed = 0;
}