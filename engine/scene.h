#ifndef _ENGINE_SCENE_H_
#define _ENGINE_SCENE_H_

#include <string>
#include <map>
#include <iterator>

#include "entity.h"

class Scene{
public:
	Scene();
	~Scene();
	
	void                     addEntity(Entity& e);
	Entity*                  getCamera();
	const std::map<std::string, Entity>& getEntities() const;
	std::string              getName();
	void                     removeEntity(std::string name);
	void                     setCameraEntity(Entity& e);
	void                     setName(std::string name);
	void                     update();

private:
	std::string name;
	std::map<std::string, Entity> entities;
	Entity* camera;
};

#endif