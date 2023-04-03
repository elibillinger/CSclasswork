// Decrement enemy health by atk
other.hp -= atk;

//destroy this bullet and trigger destroy event
instance_destroy(id,true);