#include "stage.h"

namespace Geppetto {

Stage::Stage(std::string stageName) :
game(Game::GetInstance()),
name(stageName)
{
	game.AddStage(this);
}


Stage::~Stage()
{
	for(auto entity : gEntitiesByName) {
		delete(entity.second);
	}
}


void Stage::AddEntity(Entity* e)
{
	if(gEntitiesByName.find(e->name) == gEntitiesByName.end()) {
		gEntitiesByName.insert(std::make_pair(e->name, e));
		
		if(gEntitiesByType.find(e->type) == gEntitiesByType.end()) {
			gEntitiesByType.insert(std::make_pair(e->type, std::vector<Entity*>()));
		}
		(gEntitiesByType[e->type]).push_back(e);
	}
}


Entity* Stage::GetCameraEntity() const
{
	return cameraEntity;
}


const std::map<std::string, Entity*>& Stage::GetGEntities() const
{
	return gEntitiesByName;
}


std::vector<Entity*>* Stage::GetGEntitiesByType(const std::string type)
{
	if(gEntitiesByType.find(type) != gEntitiesByType.end()) {
		return &(gEntitiesByType[type]);
	}
	
	return nullptr;
}


Entity* Stage::GetEntityByName(const std::string name)
{
	if(gEntitiesByName.find(name) != gEntitiesByName.end()) {
		return gEntitiesByName[name];
	}
	
	return nullptr;
}


Game& Stage::GetGame() const
{
	return game;
}


std::string Stage::GetName() const
{
	return name;
}


void Stage::RemoveEntity(const std::string name)
{
	if(gEntitiesByName.find(name) != gEntitiesByName.end()) {
		delete(gEntitiesByName[name]);
		gEntitiesByName.erase(name);
	}
}


void Stage::SetCameraEntity(Entity* const e)
{
	cameraEntity = e;
}


void Stage::SetName(const std::string name)
{
	this->name = name;
}


void Stage::UpdateStage()
{
	for(auto entity : gEntitiesByName) {
		if(entity.second->active) {
			entity.second->UpdateEntity();
		}
	}
	
	/* Call the derived class update() */
	Update();
}


void Stage::LoadStage()
{
	/* Call the derived class load() risponsible for adding
     * and initializing GEntities.*/
	Load();
	
	/* Let's actually to the work to load those added GEntities */
	for(auto entity : gEntitiesByName) {
		entity.second->LoadEntity();
	}
}


void Stage::Load()
{}


void Stage::Update()
{}

} // namespace Geppetto
