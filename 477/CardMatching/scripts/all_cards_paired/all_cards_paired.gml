//check to see if all the cards in the deck have been paired
function all_cards_paired(argument0){
	var deck = argument0;
	var deck_size = ds_list_size(deck);
	var all_paired = true;
	for( var i = 0; i < deck_size; i++) {
		if (deck[| i].visible == true) {
			all_paired = false;
			break;
		}
	}
	return all_paired;
}