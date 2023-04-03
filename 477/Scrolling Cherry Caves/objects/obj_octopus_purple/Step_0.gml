/// @description Control movement
if(global.game_state == states.playing){
	if(alarm[0] < 0 && !fell){
		fell = true;
		alarm[0] = room_speed * 2;
	}
	if (place_meeting(x, y+1, obj_block)) {
		gravity = 0;
		speed = 0;
		sprite_index = spr_octopus_purple_0;
}
	
	
}