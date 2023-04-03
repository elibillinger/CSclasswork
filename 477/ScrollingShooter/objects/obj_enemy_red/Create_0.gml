/// @description Red enemy

event_inherited();

// Health, attack it gives out, speed, direction it is moving.
dir = 1;

// Left and right limit - 25 pixels on each side.
start_x = x - 25;
end_x = x + 25;

// Will move down every 5 seconds.
move_down_speed = room_speed * 5;
alarm[1] = move_down_speed;

enemy_color = colors.red;
