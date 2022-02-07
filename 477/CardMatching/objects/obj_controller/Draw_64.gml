
if (global.game_state == states.WON) {
	alarm[0] = -1;
	draw_set_font(fnt_arial);
	draw_set_color(c_red);
	draw_text(room_width / 2 - 100, room_height / 2 - 100, "You Won!");
	draw_text(room_width / 2 - 150, room_height / 2 - 80, "Press ENTER to Play Again!");
} else if (global.game_state == states.LOST) {
	alarm[0] = -1;
	draw_set_font(fnt_arial);
	draw_set_color(c_red);
	draw_text(room_width / 2 - 100, room_height / 2 - 100, "You Lost!");
	draw_text(room_width / 2 - 150, room_height / 2 - 80, "Press ENTER to Play Again!");
} else {
	cur_time = ceil(alarm[0] / room_speed);
}

draw_set_font(fnt_arial);
draw_set_color(c_white);
draw_text(90,0,"Time Left: " + string(cur_time));