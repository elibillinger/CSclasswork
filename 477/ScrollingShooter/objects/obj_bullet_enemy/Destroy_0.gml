/// @description Destroy bullet

// Use built-in particle system to make a firework effect
// where the bullet was, 1/10 its size, yellow.

effect_create_above(ef_firework, x, y, 0.1, c_yellow);
audio_play_sound(snd_damage,2,false);