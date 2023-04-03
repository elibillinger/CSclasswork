#include "Game.h"

int main(int argc, char** argv) {
	// Start our game.
	Game game;

	bool bSuccess = game.Initialize();
	if (bSuccess) {
		game.RunLoop();
	}

	game.Shutdown();
	return 0;
}