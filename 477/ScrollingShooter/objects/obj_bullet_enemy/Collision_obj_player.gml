/// @description Player bullet hits enemy

// Decrement enemy health by atk
other.hp -= atk;


// Destroy this bullet and make an explosion.
instance_destroy(id, true);