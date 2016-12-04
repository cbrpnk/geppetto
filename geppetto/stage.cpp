#include "stage.h"

Stage* Stage::activeStage;


Stage::Stage(Game& parentGame, std::string stageName) : game(parentGame),
name(stageName)
{}

Stage::~Stage()
{}

void Stage::addEntity(Entity* const e)
{
	entities.insert(std::make_pair(e->name, e));
}

Stage* Stage::getActiveStage()
{
	return activeStage;
}


Entity* Stage::getCameraEntity()
{
	return cameraEntity;
}


const std::map<std::string, Entity*>& Stage::getEntities() const
{
	return entities;
}

Game& Stage::getGame()
{
	return game;
}


std::string Stage::getName()
{
	return name;
}


void Stage::load()
{
	activeStage = this;
	for(auto entity : activeStage->getEntities()) {
		entity.second->load();
	}
}


void Stage::removeEntity(const std::string name)
{
	if(entities.find(name) != entities.end()) {
		delete(entities[name]);
		entities.erase(name);
	}
}


void Stage::setCameraEntity(Entity* const e)
{
	cameraEntity = e;
}


void Stage::setName(const std::string name)
{
	this->name = name;
}


void Stage::update()
{
	for(auto entity : activeStage->getEntities()) {
		if(entity.second->active)
			entity.second->update();
	}
}
