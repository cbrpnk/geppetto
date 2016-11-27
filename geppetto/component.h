#ifndef _GEPPETTO_COMPONENT_H_
#define _GEPPETTO_COMPONENT_H_

#include <vector>

#include "entity.h"

class Component {
public:
	Entity& entity;
	
	Component(Entity& e);
	virtual ~Component();
	virtual void update();
};

#endif
