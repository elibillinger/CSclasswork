///@description pause the game
if(global.game_state == states.playing) {
	global.game_state = states.paused;
	show_debug_message("Paused = " + string(global.game_state));
	} else if (global.game_state == states.paused) {
		global.game_state = states.playing;
		show_debug_message("Playing = " + string(global.game_state));
	}