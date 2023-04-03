/// @description Parent enemy object

hp = 1;
atk = 1;
spd = 1;
enemy_color = colors.none;
dir = 1;

// Set alarm for random time for shooting.
alarm[0] = room_speed * random_range(0.5, 5);