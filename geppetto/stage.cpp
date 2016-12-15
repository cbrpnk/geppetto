#include "stage.h"

Stage::Stage(std::string stageName) :
game(Game::getInstance()),
name(stageName)
{
	game.addStage(this);
}


Stage::~Stage()
{
	for(auto entity : entitiesByName) {
		delete(entity.second);
	}
}


void Stage::addEntity(Entity* e)
{
	if(entitiesByName.find(e->name) == entitiesByName.end()) {
		entitiesByName.insert(std::make_pair(e->name, e));
		
		if(entitiesByType.find(e->type) == entitiesByType.end()) {
			entitiesByType.insert(std::make_pair(e->type, std::vector<Entity*>()));
		}
		(entitiesByType[e->type]).push_back(e);
	}
}


Entity* Stage::getCameraEntity() const
{
	return cameraEntity;
}


const std::map<std::string, Entity*>& Stage::getEntities() const
{
	return entitiesByName;
}


std::vector<Entity*>* Stage::getEntitiesByType(const std::string type)
{
	if(entitiesByType.find(type) != entitiesByType.end()) {
		return &(entitiesByType[type]);
	}
	
	return nullptr;
}


Entity* Stage::getEntityByName(const std::string name)
{
	if(entitiesByName.find(name) != entitiesByName.end()) {
		return entitiesByName[name];
	}
	
	return nullptr;
}


Game& Stage::getGame() const
{
	return game;
}


std::string Stage::getName() const
{
	return name;
}


void Stage::removeEntity(const std::string name)
{
	if(entitiesByName.find(name) != entitiesByName.end()) {
		delete(entitiesByName[name]);
		entitiesByName.erase(name);
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


void Stage::updateStage()
{
	for(auto entity : entitiesByName) {
		if(entity.second->active) {
			entity.second->updateEntity();
		}
	}
	
	/* Call the derived class update() */
	update();
}


void Stage::loadStage()
{
	/* Call the derived class load() risponsible for adding
     * and initializing entities.*/
	load();
	
	/* Let's actually to the work to load those added entities */
	for(auto entity : entitiesByName) {
		entity.second->loadEntity();
	}
}


void Stage::load()
{}


void Stage::update()
{}
