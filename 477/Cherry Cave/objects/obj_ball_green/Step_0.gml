/// @description 
if(global.game_state == states.gameover || global.game_state == states.win){
	path_start(Path1,0,0,false);
}

if(path_position == 1){
	instance_destroy();
}