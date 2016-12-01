#ifndef _GEPPETTO_COMPONENT_H_
#define _GEPPETTO_COMPONENT_H_

#include <vector>

class Entity;

class Component
{
public:
	enum class Type {
		Camera, Geometry, Physics, UserInput
	};
	
	Entity& entity;
	
	Component(Entity& e);
	virtual ~Component();
	virtual void update();
};

#endif
