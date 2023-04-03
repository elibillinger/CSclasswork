//health, attack it gives out, speed, direction it is moving
hp = 1;
atk = 1;
spd = 1;
dir = 1;

//left and right limit - 25 pixels to the left or right of alien
start_x = x - 25;
end_x = x + 25;

move_down_speed = room_speed * 5; // 5 seconds
alarm[0] = move_down_speed; // alien will move down every 5 seconds

alarm[1] = room_speed * random_range(0.5,5);
//sets alarm to a random time value between 0.5 second and 5 seconds
