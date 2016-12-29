#include "../geppetto/geppetto.h"
#include "game.h"
#include "stage.h"


int main(int argc, char **argv)
{
	// Setup Game;
	Game game;
	
	if(game.Init()) {
		new Stage();
		game.Run();
	}
	
	return 0;
}
