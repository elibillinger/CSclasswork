/// @description 

if(global.game_state == states.playing){
	y += spd * dir;
	if(place_meeting(x,y,obj_block)){
		dir *= -1;
	}
}