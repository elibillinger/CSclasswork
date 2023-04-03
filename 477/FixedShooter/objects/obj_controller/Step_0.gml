// are there any enemies left
if (!instance_exists(obj_enemy_red)){
	global.game_state = states.gameover;
}else { //an enemy is still left check if it is at the bottom of the screen
	for (var i = 0; i < instance_number(obj_enemy_red); ++i;)
{
    enemy = instance_find(obj_enemy_red,i);
	if(enemy.y >= (room_height-60))
		global.game_state = states.gameover;
}
	
}