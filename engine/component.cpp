#include <string>
#include <vector>

#include "component.h"


Component::Component(Entity& e) : entity(e) {}


Component::~Component() {}


void Component::update() {}
