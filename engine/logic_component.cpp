#include "component.h"
#include "logic_component.h"

LogicComponent::LogicComponent(Entity& e) : Component(e) {}

LogicComponent::~LogicComponent() {}

void LogicComponent::attach_update_function(void (*f)(Entity& e)) {
	update_fp = f;
}


void LogicComponent::update() {
	update_fp(entity);
}
