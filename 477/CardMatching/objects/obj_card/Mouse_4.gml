// flip the card from face-up to face-down
// and vice versa

if (visible && global.game_state == states.PAUSED) {
	face = 1;
	
	if(global.player_cards[0] == noone) {
		global.player_cards[0] = self;
	} else if (global.player_cards[0].index != self.index){
		global.player_cards[1] = self;
		
		global.game_state = states.PLAYING;
		
		alarm[0] = 1.0 * room_speed;
	}
	
}