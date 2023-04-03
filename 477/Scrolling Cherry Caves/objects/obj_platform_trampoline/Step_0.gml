/// @description Check for standing or jumping on this platform

if (place_meeting(x, y-1, obj_player)) {
	// Tell the player to jump.
	obj_player.force_jump = true;
	if (keyboard_check(vk_space)) {
		// Player jumping on trampoline, make them
		// jump higher.
		obj_player.jspd_bounce = jump_force;
	}
}
