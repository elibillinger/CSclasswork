/// @description 


var cam = view_camera[0];
var cam_x = camera_get_view_x(cam);
var cam_y = camera_get_view_y(cam);
var cam_w = camera_get_view_width(cam);
var cam_h = camera_get_view_height(cam);


// Bullet only moves if we are in playing state.
if (global.game_state == states.playing) {
	if (x > cam_x && x < (cam_x + cam_w) && y > cam_y && y < (cam_y + cam_h)) {
		speed = spd;
	} else {
		instance_destroy(id,false);
	}
} else {
	speed = 0;
}