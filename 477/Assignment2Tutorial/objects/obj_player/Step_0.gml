// player movement

// if right arrow key is pressed move right
if (keyboard_check(vk_right)) x += 4;

// if right arrow key is pressed move left
if (keyboard_check(vk_left)) x -= 4;

// if right arrow key is pressed move down
if (keyboard_check(vk_down)) y += 4;

// if right arrow key is pressed move up
if (keyboard_check(vk_up)) y -= 4;

//have player point at the position of the mouse
image_angle = point_direction(x,y,mouse_x,mouse_y);

//player shooting
//if left mouse is pressed and cooldown is below 1
//create bullet object  and set how long until the player can shoot again (in frames)
if (mouse_check_button(mb_left)) && (cooldown < 1)
{
	instance_create_layer(x,y, "BulletsLayer", obj_bullet);
	cooldown = 10;
}
// decrease the cooldown to be able to shoot again
cooldown = cooldown - 1;
