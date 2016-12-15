#include "../geppetto/geppetto.h"
#include "demo_game.h"
#include "demo_stage.h"


int main(int argc, char **argv)
{
	// Setup Game;
	DemoGame demoGame;
	
	if(demoGame.init()) {
		new DemoStage();
		
		if(demoGame.loadStage("Demo_Stage")) {
			demoGame.run();
		}
	}
	
	return 0;
}
