/// @description Red enemy that walks on a path

event_inherited();

spd = 2;

path_start(Path2, spd, path_action_reverse, false);

enemy_color = colors.red;