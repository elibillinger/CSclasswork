/// @description 

// Seed random number generator.
randomize();

enum states {
	playing,
	paused,
	gameover
};

global.game_state = states.playing;

enum colors {
	none,
	red,
	blue
};
