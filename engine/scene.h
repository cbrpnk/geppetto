#ifndef _ENGINE_SCENE_H_
#define _ENGINE_SCENE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"

class Scene {
public:
	Scene();
	~Scene();
	
	
	void                     addEntity(Entity& e);
	static Scene*            getActiveScene();
	Entity*                  getCameraEntity();
	const std::map<std::string, Entity>& getEntities() const;
	std::string              getName();
	void                     load();
	void                     removeEntity(std::string name);
	void                     setCameraEntity(Entity& e);
	void                     setName(std::string name);
	static void                     update();

private:
	std::string name;
	std::map<std::string, Entity> entities;
	Entity* cameraEntity;
	static Scene* activeScene;
};

#endif
