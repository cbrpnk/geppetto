#include "../geppetto/geppetto.h"
#include "game.h"
#include "stage.h"


int main(int argc, char **argv)
{
	// Setup Game;
	Game game;
	
	if(game.init()) {
		new Stage();
		
		if(game.loadGStage("Stage")) {
			game.run();
		}
	}
	
	return 0;
}
