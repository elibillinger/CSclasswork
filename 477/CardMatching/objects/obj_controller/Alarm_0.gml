// alarm for when overall game time is up
// check for win/lose conditions

cur_time = 0;


if(all_cards_paired(global.deck) == true) {
	global.game_state = states.WON;
} else {
	global.game_state = states.LOST;
}