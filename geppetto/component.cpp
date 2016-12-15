#include <string>
#include <vector>

#include "component.h"
#include "entity.h"


Component::Component(Entity& e) :
gGame(e.getGGame()),
gStage(e.getGStage()),
entity(e)
{}


Component::~Component()
{}


void Component::update()
{}
