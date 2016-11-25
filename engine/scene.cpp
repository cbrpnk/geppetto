#include "scene.h"

Scene* Scene::activeScene;


Scene::Scene(Game& parentGame) : game(&parentGame) {}


Scene::~Scene() {}


void Scene::addEntity(Entity* e) {
	entities.insert(std::make_pair(e->name, e));
}

Scene* Scene::getActiveScene() {
	return activeScene;
}


Entity* Scene::getCameraEntity() {
	return cameraEntity;
}


const std::map<std::string, Entity*>& Scene::getEntities() const {
	return entities;
}

Game* Scene::getGame() {
	return game;
}


std::string Scene::getName() {
	return name;
}


void Scene::load() {
	//TODO: Call the load method on all scene entities
	activeScene = this;
}


void Scene::removeEntity(std::string name) {
	if(entities.find(name) != entities.end()) {
		entities.erase(name);
	}
}


void Scene::setCameraEntity(Entity* e) {
	cameraEntity = e;
}


void Scene::setName(std::string name) {
	this->name = name;
}


void Scene::update() {
	for(auto entity : activeScene->getEntities()) {
		entity.second->update();
	}
}
