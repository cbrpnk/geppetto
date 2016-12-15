#include <string>
#include <vector>
#include "../geppetto/geppetto.h"
#include "demo_stage.h"
#include "player.h"
#include "cube.h"


const size_t DemoStage::NCubes = 100;


DemoStage::DemoStage() :
Stage("Demo_Stage")
{}


DemoStage::~DemoStage()
{}


void DemoStage::load()
{
	new Player();
	
	// Create cubes
	for(size_t i=0; i<DemoStage::NCubes; ++i) {
		new Cube("Cube" + std::to_string(i));
	}
}

void DemoStage::update()
{}
