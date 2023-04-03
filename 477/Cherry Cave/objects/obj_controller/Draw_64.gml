/// @description Score, lives, cherries
draw_set_color(c_black);
draw_rectangle(0,0,room_width,40,false);
draw_set_color(c_white);
draw_set_font(fnt_score);

draw_text(20,10,"SCORE: " + string(score));
draw_sprite_ext(spr_cherry,-1,(room_width/2)-32,20,0.5,0.5,0,c_white,1);
draw_text(room_width/2,10,string(global.cherries) + "/" + string(global.max_cherries));

draw_sprite_ext(spr_player_idle,-1,room_width-110,20,0.5,0.5,0,c_white,1);
draw_text(room_width-100,10," x " + string(lives));

if(global.game_state == states.gameover){
	draw_text(room_width/2,room_height/2,"GAMEOVER");
}

if(global.game_state == states.win){
	draw_text(room_width/2,room_height/2,"YOU WIN");
}