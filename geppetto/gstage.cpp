#include "gstage.h"

GStage::GStage(std::string gStageName) :
gGame(GGame::getInstance()),
name(gStageName)
{
	gGame.addGStage(this);
}


GStage::~GStage()
{
	for(auto gEntity : gEntitiesByName) {
		delete(gEntity.second);
	}
}


void GStage::addGEntity(GEntity* e)
{
	if(gEntitiesByName.find(e->name) == gEntitiesByName.end()) {
		gEntitiesByName.insert(std::make_pair(e->name, e));
		
		if(gEntitiesByType.find(e->type) == gEntitiesByType.end()) {
			gEntitiesByType.insert(std::make_pair(e->type, std::vector<GEntity*>()));
		}
		(gEntitiesByType[e->type]).push_back(e);
	}
}


GEntity* GStage::getCameraGEntity() const
{
	return cameraGEntity;
}


const std::map<std::string, GEntity*>& GStage::getGEntities() const
{
	return gEntitiesByName;
}


std::vector<GEntity*>* GStage::getGEntitiesByType(const std::string type)
{
	if(gEntitiesByType.find(type) != gEntitiesByType.end()) {
		return &(gEntitiesByType[type]);
	}
	
	return nullptr;
}


GEntity* GStage::getGEntityByName(const std::string name)
{
	if(gEntitiesByName.find(name) != gEntitiesByName.end()) {
		return gEntitiesByName[name];
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


void GStage::removeGEntity(const std::string name)
{
	if(gEntitiesByName.find(name) != gEntitiesByName.end()) {
		delete(gEntitiesByName[name]);
		gEntitiesByName.erase(name);
	}
}


void GStage::setCameraGEntity(GEntity* const e)
{
	cameraGEntity = e;
}


void GStage::setName(const std::string name)
{
	this->name = name;
}


void GStage::updateGStage()
{
	for(auto gEntity : gEntitiesByName) {
		if(gEntity.second->active) {
			gEntity.second->updateGEntity();
		}
	}
	
	/* Call the derived class update() */
	update();
}


void GStage::loadGStage()
{
	/* Call the derived class load() risponsible for adding
     * and initializing GEntities.*/
	load();
	
	/* Let's actually to the work to load those added GEntities */
	for(auto gEntity : gEntitiesByName) {
		gEntity.second->loadGEntity();
	}
}


void GStage::load()
{}


void GStage::update()
{}
