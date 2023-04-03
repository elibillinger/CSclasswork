/// @description Build the car

var half = sprite_width /2;

var tire1 = instance_create_layer(x-half+12,y,"Instances",obj_car_tire);
physics_joint_revolute_create(id,tire1,tire1.x,tire1.y,0,0,0,0,0,0,false);

var tire2 = instance_create_layer(x+half-12,y,"Instances",obj_car_tire);
physics_joint_revolute_create(id,tire2,tire2.x,tire2.y,0,0,0,0,0,0,false);
