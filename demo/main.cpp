#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "../geppetto/geppetto.h"
#include "demo_scene.h"


int main(int argc, char **argv) {
	// Setup Game;
	Game demoGame("Demo", 800, 600);
	
	if(demoGame.init()) {
		DemoScene demoScene(demoGame);
		
		demoScene.load();
		demoGame.run();
	}
	
	return 0;
}
