#include "gstage.h"

GStage::GStage(std::string gStageName) :
gGame(GGame::getInstance()),
name(gStageName)
{
	gGame.addGStage(this);
}


GStage::~GStage()
{
	for(auto entity : entitiesByName) {
		delete(entity.second);
	}
}


void GStage::addEntity(Entity* e)
{
	if(entitiesByName.find(e->name) == entitiesByName.end()) {
		entitiesByName.insert(std::make_pair(e->name, e));
		
		if(entitiesByType.find(e->type) == entitiesByType.end()) {
			entitiesByType.insert(std::make_pair(e->type, std::vector<Entity*>()));
		}
		(entitiesByType[e->type]).push_back(e);
	}
}


Entity* GStage::getCameraEntity() const
{
	return cameraEntity;
}


const std::map<std::string, Entity*>& GStage::getEntities() const
{
	return entitiesByName;
}


std::vector<Entity*>* GStage::getEntitiesByType(const std::string type)
{
	if(entitiesByType.find(type) != entitiesByType.end()) {
		return &(entitiesByType[type]);
	}
	
	return nullptr;
}


Entity* GStage::getEntityByName(const std::string name)
{
	if(entitiesByName.find(name) != entitiesByName.end()) {
		return entitiesByName[name];
	}
	
	return nullptr;
}


GGame& GStage::getGGame() const
{
	return gGame;
}


std::string GStage::getName() const
{
	return name;
}


void GStage::removeEntity(const std::string name)
{
	if(entitiesByName.find(name) != entitiesByName.end()) {
		delete(entitiesByName[name]);
		entitiesByName.erase(name);
	}
}


void GStage::setCameraEntity(Entity* const e)
{
	cameraEntity = e;
}


void GStage::setName(const std::string name)
{
	this->name = name;
}


void GStage::updateGStage()
{
	for(auto entity : entitiesByName) {
		if(entity.second->active) {
			entity.second->updateEntity();
		}
	}
	
	/* Call the derived class update() */
	update();
}


void GStage::loadGStage()
{
	/* Call the derived class load() risponsible for adding
     * and initializing entities.*/
	load();
	
	/* Let's actually to the work to load those added entities */
	for(auto entity : entitiesByName) {
		entity.second->loadEntity();
	}
}


void GStage::load()
{}


void GStage::update()
{}
