/// @description Move right

// While holding down right arrow key, Jomathan should glide
// to the right.

// His pivot point is in the middle, so take
// that into account when calculating hitting
// the right wall.

var cam = view_camera[0];
var cam_w = camera_get_view_width(cam);
if (global.game_state == states.playing && x < cam_w - sprite_width / 2) {
	x += spd;
}