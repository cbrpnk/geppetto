#ifndef _GEPPETTO_SCENE_H_
#define _GEPPETTO_SCENE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"

class Game;

class Scene {
public:
	Scene(Game& parentGame);
	~Scene();
	
	
	void                                 addEntity(Entity* e);
	static Scene*                        getActiveScene();
	Entity*                              getCameraEntity();
	const std::map<std::string, Entity*>& getEntities() const;
	Game*                                getGame();
	std::string                          getName();
	virtual void                         load();
	void                                 removeEntity(std::string name);
	void                                 setCameraEntity(Entity* e);
	void                                 setName(std::string name);
	static void                          update();

private:
	Game* game;
	std::string name;
	std::map<std::string, Entity*> entities;
	Entity* cameraEntity;
	static Scene* activeScene;
};

#endif
