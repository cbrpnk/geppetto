#ifndef _GEPPETTO_STAGE_H_
#define _GEPPETTO_STAGE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"


namespace Geppetto {

class Game;

class Stage
{
public:
	Stage(std::string stageName);
	virtual ~Stage();
	
	Game&       GetGame() const;
	std::string GetName() const;
	void        SetName(const std::string name);
	
	
	//////////////////// Deal with GEntities /////////////////////
	
	
	void                                  AddEntity(Entity* e);
	Entity*                               GetCameraEntity() const;
	const std::map<std::string, Entity*>& GetGEntities() const;
	std::vector<Entity*>*                 GetGEntitiesByType(const std::string type);
	Entity*                               GetEntityByName(const std::string name);
	void                                  RemoveEntity(const std::string name);
	void                                  SetCameraEntity(Entity* const e);
	
	
	/////////////////// Load/Update //////////////////////////
	
	
	// loadStage() is called by Game::loadStage()
	void LoadStage();
	// Called on every frame by Game::run()
	void UpdateStage();
	
	// Methods meant to be defined by the derived class are called by
    // loadStage() and updateStage() respectively
	virtual void Load();
	virtual void Update();


protected:
	// Reference to the current Game
	Game& game;
	// Unique identifier to a Stage
	std::string name;
	// All the GEntities in this Stage
	std::map<std::string, Entity*> gEntitiesByName;
	// Maps a User defined Entity type to the set of GEntities that are of
    // that type. Used by getGEntitiesByType().
	std::map<std::string, std::vector<Entity*>> gEntitiesByType;
	// Entity that possess a CameraComponent used by Game::render()
	Entity* cameraEntity;
};

} // namespace Geppetto

#endif
