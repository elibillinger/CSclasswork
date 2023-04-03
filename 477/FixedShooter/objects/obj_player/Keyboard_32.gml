if(global.game_state == states.playing && can_shoot) {
	//create a bullet and shoot it straight up from player, then rest delay and timer
	can_shoot = false;
	var bullet = instance_create_layer(x,y,"Instances",obj_bullet_player);
	bullet.atk = atk;
	bullet.direction = point_direction(x,y,x,y-1); //straight up
	bullet.speed = bullet.spd; // set built-in speed variable
	alarm[0] = shoot_delay;
	
}