#include <string>
#include <vector>

#include "component.h"
#include "entity.h"


Component::Component(Entity& e) :
game(e.getGame()),
stage(e.getStage()),
entity(e)
{}


Component::~Component()
{}


void Component::update()
{}
