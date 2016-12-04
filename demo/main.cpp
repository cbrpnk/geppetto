#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "../geppetto/geppetto.h"
#include "demo_stage.h"


int main(int argc, char **argv)
{
	// Setup Game;
	Game demoGame("Demo", 800, 600);
	
	if(demoGame.init()) {
		demoGame.addStage(new DemoStage(demoGame, "demo_stage"));
		
		demoGame.loadStage("demo_stage");
		demoGame.run();
	}
	
	return 0;
}
