// create an enemy in random location within the room and reset the alarm
instance_create_layer(random(room_width),random(room_height), "EnemyLayer", obj_enemyspawn);
alarm[0] = spawnrate;