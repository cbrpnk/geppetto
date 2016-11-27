#include "stage.h"

Stage* Stage::activeStage;


Stage::Stage(Game& parentGame) : game(&parentGame) {}


Stage::~Stage() {}


void Stage::addEntity(Entity* e) {
	entities.insert(std::make_pair(e->name, e));
}

Stage* Stage::getActiveStage() {
	return activeStage;
}


Entity* Stage::getCameraEntity() {
	return cameraEntity;
}


const std::map<std::string, Entity*>& Stage::getEntities() const {
	return entities;
}

Game* Stage::getGame() {
	return game;
}


std::string Stage::getName() {
	return name;
}


void Stage::load() {
	//TODO: Call the load method on all stage entities
	activeStage = this;
}


void Stage::removeEntity(std::string name) {
	if(entities.find(name) != entities.end()) {
		entities.erase(name);
	}
}


void Stage::setCameraEntity(Entity* e) {
	cameraEntity = e;
}


void Stage::setName(std::string name) {
	this->name = name;
}


void Stage::update() {
	for(auto entity : activeStage->getEntities()) {
		entity.second->update();
	}
}
