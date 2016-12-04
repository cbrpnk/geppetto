#include <string>
#include "../geppetto/geppetto.h"
#include "demo_stage.h"
#include "player.h"
#include "cube.h"

DemoStage::DemoStage(Game& ParentGame, std::string name) : Stage(ParentGame, name)
{}

DemoStage::~DemoStage()
{}

void DemoStage::load()
{
	
	Entity* player = new Entity(*this);
	player->name = "Player";
	player->addCustomClass(new Player());
	addEntity(player);
	setCameraEntity(player);
	
	// Create cubes
	for(int i=0; i<100; ++i) {
		Entity* entity = new Entity(*this);
		entity->name = "Cube" + std::to_string(i);
		entity->addCustomClass(new Cube());
		addEntity(entity);
	}
	
	Stage::load();
}

void DemoStage::update()
{
	Stage::update();
}
