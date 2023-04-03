/// @description Move left

// While holding down left arrow key, Jomathan should glide
// to the left.

// His pivot point is in the middle, so take
// that into account when calculating hitting
// the left wall.

if (global.game_state == states.playing && x > 0 + sprite_width / 2) {
	x -= spd;
}