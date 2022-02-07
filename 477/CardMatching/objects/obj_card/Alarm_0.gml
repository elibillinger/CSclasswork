// alarm for when two cards have been selected 
// matching logic here when alarm goes off
if (global.player_cards[0].type == global.player_cards[1].type) {
	//cards match make them invisible
	global.player_cards[0].visible = false;
	global.player_cards[1].visible = false;
}
		
global.player_cards[0].face = 0;
global.player_cards[1].face = 0;
global.player_cards[0] = noone;
global.player_cards[1] = noone;

global.game_state = states.PAUSED;

//check if all cards have been paired
if(all_cards_paired(global.deck) == true) {
			global.game_state = states.WON;
		}