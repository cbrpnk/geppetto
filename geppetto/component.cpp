#include <string>
#include <vector>

#include "component.h"
#include "gentity.h"


Component::Component(GEntity& e) :
gGame(e.getGGame()),
gStage(e.getGStage()),
gEntity(e)
{}


Component::~Component()
{}


void Component::update()
{}
