/// @description manage the overall game

if(global.game_state = states.dead){
	lives--;
	alarm[0] = room_speed * 1;
	global.game_state = states.playing;
	
	if(lives <= 0){
		global.game_state = states.gameover;
	}
}
