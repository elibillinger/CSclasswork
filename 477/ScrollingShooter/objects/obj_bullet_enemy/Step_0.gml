/// @description 

// Bullet only moves if we are in playing state.
if (global.game_state == states.playing) {
	speed = spd;
	if(color == colors.blue){
		sprite_index = spr_bullet_blue;
	} else {
		sprite_index = spr_bullet_red;
	}
} else {
	speed = 0;
}