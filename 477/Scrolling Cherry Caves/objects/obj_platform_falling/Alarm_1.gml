/// @description Destroy platform and respawn one

if (!place_meeting(startx, starty, obj_player)) {
	instance_create_layer(startx, starty, "Instances", obj_platform_falling);
	instance_destroy();
} else {
	visible = false;
	alarm[1] = room_speed * 0.2;
}