#include <string>
#include <vector>

#include "gcomponent.h"
#include "gentity.h"


GComponent::GComponent(GEntity& e) :
gGame(e.getGGame()),
gStage(e.getGStage()),
gEntity(e)
{}


GComponent::~GComponent()
{}


void GComponent::update()
{}
