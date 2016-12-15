#ifndef _GSTAGE_H_
#define _GSTAGE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"

class GGame;

class GStage
{
public:
	GStage(std::string gStageName);
	virtual ~GStage();
	
	GGame&       getGGame() const;
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
	
	
	/* loadGStage() is called by GGame::loadGStage() */
	void loadGStage();
	/* Called on every frame by GGame::run() */
	void updateGStage();
	
	/* Methods meant to be defined by the derived class; are called by
     * loadGStage() and updateGStage() respectively
     */
	virtual void load();
	virtual void update();


protected:
	/* Reference to the current GGame */
	GGame& gGame;
	/* Unique identifier to a GStage */
	std::string name;
	/* All the entities in this GStage */
	std::map<std::string, Entity*> entitiesByName;
	/* Maps a user defined entity type to the set of entities that are of
     * that type. Used by getEntitiesByType().
     */
	std::map<std::string, std::vector<Entity*>> entitiesByType;
	/* Entity that possess a CameraComponent used by GGame::render() */
	Entity* cameraEntity;
};

#endif
