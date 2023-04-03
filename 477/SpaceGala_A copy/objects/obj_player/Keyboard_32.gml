/// @description Player shoot

if (global.game_state == states.playing && can_shoot) {
	// Create a bullet and shoot it straight up.
	can_shoot = false;
	var bullet = instance_create_layer(x, y, "Instances", obj_bullet_player);
	bullet.atk = atk;
	bullet.direction = point_direction(x, y, x, y-1);
	bullet.speed = bullet.spd;
	alarm[0] = shoot_delay;
}