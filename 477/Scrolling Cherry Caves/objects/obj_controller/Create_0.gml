/// @description 

enum states {
	playing,
	dead,
	gameover,
	won
};

global.game_state = states.playing;

global.money = score;

global.mov_platform_spd = 1;

global.mov_platform_dir = 1;