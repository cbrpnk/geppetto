#ifndef _GEPPETTO_STAGE_H_
#define _GEPPETTO_STAGE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"

class Game;

class Stage
{
public:
	Stage(std::string stageName);
	virtual ~Stage();
	
	Game&       getGame() const;
	std::string getName() const;
	void        setName(const std::string name);
	
	
	//////////////////// Deal with Entities /////////////////////
	
	
	void                                   addEntity(Entity* e);
	Entity*                                getCameraEntity() const;
	const std::map<std::string, Entity*>&  getEntities() const;
	std::vector<Entity*>*                  getEntitiesByType(const std::string type);
	Entity*                                getEntityByName(const std::string name);
	void                                   removeEntity(const std::string name);
	void                                   setCameraEntity(Entity* const e);
	
	
	/////////////////// Load/Update //////////////////////////
	
	
	/* loadStage() is called by Game::loadStage() */
	void loadStage();
	/* Called on every frame by Game::run() */
	void updateStage();
	
	/* Methods meant to be defined by the derived class; are called by
     * loadStage() and updateStage() respectively
     */
	virtual void load();
	virtual void update();


protected:
	/* Reference to the current game */
	Game& game;
	/* Unique identifier to a stage */
	std::string name;
	/* All the entities in this stage */
	std::map<std::string, Entity*> entitiesByName;
	/* Maps a user defined entity type to the set of entities that are of
     * that type. Used by getEntitiesByType().
     */
	std::map<std::string, std::vector<Entity*>> entitiesByType;
	/* Entity that possess a CameraComponent used by Game::render() */
	Entity* cameraEntity;
};

#endif
