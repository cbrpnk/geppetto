#include <string>
#include <vector>
#include "../geppetto/geppetto.h"
#include "stage.h"
#include "player.h"
#include "cube.h"


const size_t Stage::NCubes = 100;


Stage::Stage() :
Geppetto::Stage("Stage")
{}


Stage::~Stage()
{}


void Stage::Load()
{
	new Player();
	
	// Create cubes
	for(size_t i=0; i<Stage::NCubes; ++i) {
		new Cube("Cube" + std::to_string(i));
	}
}

void Stage::Update()
{
}
