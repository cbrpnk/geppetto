#ifndef _ENGINE_LOGIC_COMPONENT_H_
#define _ENGINE_LOGIC_COMPONENT_H_

#include "component.h"

class Entity;

class LogicComponent : public Component {
public:
	LogicComponent(Entity& e);
	~LogicComponent();
	void attach_update_function(void (*f)(Entity& e));
	void update();
private:
	void (*update_fp)(Entity& e);
};

#endif
