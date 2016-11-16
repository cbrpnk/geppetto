#include "scene.h"


Scene::Scene() {}
Scene::~Scene() {}


void Scene::addEntity(Entity& e) {
	entities.insert(std::make_pair(e.name, e));
}


const std::map<std::string, Entity>& Scene::getEntities() const {
	return entities;
}


std::string Scene::getName() {
	return name;
}


void Scene::removeEntity(std::string name) {
	if(entities.find(name) != entities.end()) {
		entities.erase(name);
	}
}


void Scene::setName(std::string name) {
	this->name = name;
}


void Scene::update() {
	for(auto entity : entities) {
		entity.second.update();
	}
}
