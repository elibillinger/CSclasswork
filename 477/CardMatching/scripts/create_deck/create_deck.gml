// create the deck by setting cards 
function create_deck(argument0,argument1){
	var deck = argument0;
	var deckSize = argument1;
	
	for (var i = 0; i < deckSize; i++) {
		//create a new obj_card at position 0,0 for now
		var card = instance_create_layer(0,0,"Instances",obj_card);
		ds_list_add(deck,card);
	}

	for (var i = 0; i < deckSize; i++) {
		// Initialize every card in the deck
		deck[| i].face = 0;
		deck[| i].index = i;
		deck[| i].type = i % cards_number;
		deck[| i].visible = false;
	}
	
	shuffle_cards(deck);
}