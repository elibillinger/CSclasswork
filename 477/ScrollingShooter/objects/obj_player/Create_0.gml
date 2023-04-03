/// @description Create Jonathan SpacePants


// Health.
hp = 10;

// Default speed of 3 pixels per frame, so about 180 pixels per second.
spd = 3;

// Adding delay to player shooting so only 5 bullets per second.
atk = 1;
can_shoot = true;
shoot_delay = room_speed * 0.2;

// Player should be flying upwards.
direction = point_direction(x, y, x, y-1);

// Default player to be blue.
sprite_index = spr_player_blue;
if (room == rm_level_1) {
	color = colors.none;
} else {
	color = colors.blue;
}