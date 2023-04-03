/// @description Re-spawn Berry

global.lives = global.lives - 1;
show_debug_message(global.lives);
if (global.lives <= 0) {
	global.game_state = states.gameover;
} else {
	room_restart();
	global.game_state = states.playing;
	score = global.money;
}
