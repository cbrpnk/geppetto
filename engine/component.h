#ifndef _ENGINE_COMPONENT_H_
#define _ENGINE_COMPONENT_H_

#include <string>
#include <vector>

#include "entity.h"

class Component {
public:
	Entity& entity;
	std::string name;
	
	Component(Entity& e);
	virtual ~Component();
	virtual void update();
};

#endif
