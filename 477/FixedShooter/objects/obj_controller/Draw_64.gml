draw_set_font(fnt_score);
draw_set_color(c_white);
draw_text(30,30,"SCORE: " + string(score));

switch (global.game_state) {
	case states.paused:
		draw_text(900,20,"PAUSED");
		break;
	case states.gameover:
		draw_text(900,20,"GAME OVER");
		break;
}

if(instance_exists(obj_player)){
	var xhp = 30;
	repeat(obj_player.hp){
		draw_sprite(spr_life, 0, xhp, 750);
		xhp += 30;
	}
}