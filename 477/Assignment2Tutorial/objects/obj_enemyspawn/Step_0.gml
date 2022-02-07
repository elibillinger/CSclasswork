//scale up enemy until it reaches 1
image_xscale = min(image_xscale + 0.02,1);
image_yscale = image_xscale;

//once the scale is 1 change the instance into an enemy
if image_xscale == 1 instance_change(obj_enemy, true);