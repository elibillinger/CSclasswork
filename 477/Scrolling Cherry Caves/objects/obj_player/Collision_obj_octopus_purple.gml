/// @description Can bonk green octopus on the head and kill it

if ((y + sprite_height / 2) < other.y) {
	effect_create_above(ef_smoke,x,y,1,c_white);
	instance_destroy(other);
	audio_play_sound(snd_squash,1,false);
	force_jump = true;
} else {
	effect_create_above(ef_explosion,x,y,1,c_white);
	global.game_state = states.dead;
	audio_play_sound(snd_damage,2,false);
	instance_destroy();
}