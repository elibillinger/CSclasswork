/// @description 

global.cherries += 1;
instance_destroy();

audio_play_sound(snd_cherry,1,false);

if(global.cherries == global.max_cherries){
	instance_create_layer(75,400,"Instances",obj_goal);
}