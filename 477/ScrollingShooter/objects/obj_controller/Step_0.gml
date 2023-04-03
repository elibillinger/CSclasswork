/// @description 

// Are there any enemies left.
if (global.game_state == states.gameover && !instance_exists(obj_enemy_red)){
	//global.game_state = states.gameover;
	
	if (room_exists(room_next(room))) {
		room_goto_next();
	}
}


if(!instance_exists(obj_enemy_red) && !instance_exists(obj_enemy_walker_red) && !instance_exists(obj_enemy_blue) && !instance_exists(obj_ufo)){
	global.game_state = states.gameover;
}