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
	Stage(Game& parentGame);
	~Stage();
	
	
	void                                  addEntity(Entity* const e);
	static Stage*                         getActiveStage();
	Entity*                               getCameraEntity();
	const std::map<std::string, Entity*>& getEntities() const;
	Game*                                 getGame();
	std::string                           getName();
	virtual void                          load();
	void                                  removeEntity(const std::string name);
	void                                  setCameraEntity(Entity* const e);
	void                                  setName(const std::string name);
	virtual void                          update();

protected:
	Game* game;
	std::string name;
	std::map<std::string, Entity*> entities;
	Entity* cameraEntity;
	static Stage* activeStage;
};

#endif
