#include "stage.h"

namespace Geppetto {

Stage::Stage(std::string stageName) :
game(Game::GetInstance()),
name(stageName)
{
    Stage* activeStage = Game::GetInstance().GetActiveStage();
    if(activeStage != nullptr) {
        delete activeStage;
    }
    Game::GetInstance().SetActiveStage(this);
}


Stage::~Stage()
{
    for(auto entity : entitiesByName) {
        delete(entity.second);
    }
}


void Stage::AddEntity(Entity* e)
{
    if(entitiesByName.find(e->name) == entitiesByName.end()) {
        entitiesByName.insert(std::make_pair(e->name, e));
        
        if(entitiesByType.find(e->type) == entitiesByType.end()) {
            entitiesByType.insert(std::make_pair(e->type, std::vector<Entity*>()));
        }
        (entitiesByType[e->type]).push_back(e);
    }
}


Entity* Stage::GetCameraEntity() const
{
    return cameraEntity;
}


const std::map<std::string, Entity*>& Stage::GetEntities() const
{
    return entitiesByName;
}


std::vector<Entity*>* Stage::GetEntitiesByType(const std::string type)
{
    if(entitiesByType.find(type) != entitiesByType.end()) {
        return &(entitiesByType[type]);
    }
    
    return nullptr;
}


Entity* Stage::GetEntityByName(const std::string name)
{
    if(entitiesByName.find(name) != entitiesByName.end()) {
        return entitiesByName[name];
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
    if(entitiesByName.find(name) != entitiesByName.end()) {
        entitiesByName.erase(name);
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
    for(auto entity : entitiesByName) {
        if(entity.second->active) {
            entity.second->UpdateEntity();
        }
    }
    
    /* Call the derived class update() */
    Update();
}


void Stage::Update()
{}

} // namespace Geppetto
