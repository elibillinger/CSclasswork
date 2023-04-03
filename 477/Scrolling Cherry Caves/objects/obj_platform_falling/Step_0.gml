/// @description Trigger falling when player is on it.
// After it leaves the world, destroy and respawn.

if (place_meeting(x, y-1, obj_player) && !triggered) {
	triggered = true;
	alarm[0] = room_speed * 1;
}