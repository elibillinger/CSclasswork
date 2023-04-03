/// @description 

global.cherries = 0;
global.max_cherries = instance_number(obj_cherry);
global.startx = obj_player.x;
global.starty = obj_player.y;
lives = 3;

enum states {
	playing,
	dead,
	gameover,
	win
};
global.game_state = states.playing;
