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
		DemoStage demoStage(demoGame);
		
		demoStage.load();
		demoGame.run();
	}
	
	return 0;
}
