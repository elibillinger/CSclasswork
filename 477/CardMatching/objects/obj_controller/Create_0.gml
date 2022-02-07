// obj_controller - manages state of the game
enum states {
	PAUSED,
	PLAYING,
	WON,
	LOST
}

global.game_state = states.PAUSED;
cards_number = 8;

global.player_cards = [noone,noone];

play_time = 60;
cur_time = 60;

global.deck = ds_list_create();
var deck_size = cards_number * 2;

create_deck(global.deck,deck_size);

alarm[0] = play_time * room_speed;