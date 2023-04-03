// health
hp = 10;

//default speed of 3 pixels per frame
spd = 3;

atk = 1; //damage player gives
can_shoot = true; //change to false when we hit space bar, then back to ture after short_delay
shoot_delay = room_speed * 0.2; // add delay so we shoot 5 bullets per second
// adding a dealy to player shooting, otherwise hitting the spacebar sends out way too many bullets
