//shuffle cards method
//pass it a deck and it will shuffle and "deal" them out
function shuffle_cards(argument0){
	var deck = argument0;
	
	randomize();
	ds_list_shuffle(deck);
	
	var cards_x = 70;
	var cards_y = 90;
	var deck_size = ds_list_size(deck);
	
	//position cards on the screen
	var cards = 1;
	for (var i = 0; i < deck_size; i++) {
		deck[| i].x = cards_x;
		deck[| i].y = cards_y;
		deck[| i].index = i;
		deck[| i].visible = true;
		if (cards % 4 == 0) {
			cards_x = 70;
			cards_y += 160;
		} else {
			cards_x += 110;
		}
		
		cards += 1;
	}
}