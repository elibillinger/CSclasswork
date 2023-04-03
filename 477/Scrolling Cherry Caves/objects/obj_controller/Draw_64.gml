/// @description Score, lives, cherries GUI

draw_set_color(c_black);
draw_rectangle(0, 0, room_width, 40, false);
draw_set_color(c_white);
draw_set_font(fnt_score);

draw_text(20, 10, "SCORE: " + string(score));

draw_sprite_ext(spr_player_idle,-1,150,20,0.5,0.5,0,c_white,1);
draw_text(160,10," x " + string(global.lives));

if(global.game_state == states.gameover){
	draw_text(1280/2,720/2,"GAMEOVER");
}

if(global.game_state == states.won){
	draw_set_color(c_black)
	draw_text(1280/2,720/2,"YOU WIN");
}