/// @description Destroy player

effect_create_above(ef_explosion, x, y, 1, c_dkgray);


// If player just exploded, game is over.
global.game_state = states.gameover;
