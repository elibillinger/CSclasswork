/// @description Pause the game

if (global.game_state == states.playing) {
	global.game_state = states.paused;
	
	show_debug_message("PAUSED = " + string(global.game_state));
	audio_play_sound(snd_esc,1,false);
} else if (global.game_state == states.paused) {
	global.game_state = states.playing;
	
	show_debug_message("PLAYING = " + string(global.game_state));
}