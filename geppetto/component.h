#ifndef _GEPPETTO_COMPONENT_H_
#define _GEPPETTO_COMPONENT_H_

#include <vector>

class Entity;
class Game;
class Stage;

class Component
{
public:
	enum class Type {
		Camera, Geometry, Physics, UserInput
	};
	
	Game&   game;
	Stage&  stage;
	Entity& entity;
	
	Component(Entity& e);
	virtual ~Component();
	virtual void update();
};

#endif
