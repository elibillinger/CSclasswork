// Alarm went of, move alien down 30 and reset alarm
if(global.game_state == states.playing) {
	y += 30;
}
alarm[0] = move_down_speed;