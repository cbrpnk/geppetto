#include <iostream>
#include <memory>

#include "component.h"
#include "component_controller.h"
#include "camera_component.h"
#include "geometry_component.h"
#include "physics_component.h"
#include "user_input_component.h"
#include "entity.h"


ComponentController::ComponentController(Entity& e) : entity(e) {}
ComponentController::~ComponentController() {}


void ComponentController::add(std::string name) {
	if(name == "Camera") {
		components[name] = std::unique_ptr<Component> (new CameraComponent(entity));
	} else if(name == "Geometry") {
		components[name] = std::unique_ptr<Component> (new GeometryComponent(entity));
	}  else if(name == "Physics") {
		components[name] = std::unique_ptr<Component> (new PhysicsComponent(entity));
	} else if(name == "UserInput") {
		components[name] = std::unique_ptr<Component> (new UserInputComponent(entity));
	} else {
		std::cout << name << " is not a component.\n";
	}
}


bool ComponentController::isEnabled(std::string name) {
	if(components.find(name) != components.end()) {
		return true;
	}
	return false;
}


void ComponentController::remove(std::string name) {
	if(components.find(name) == components.end()) {
		std::cout << "This entity doesn't have a " << name << " component\n";
	} else {
		components.erase(name);
	}
}


void ComponentController::updateAll() {
	for(auto it : components) {
		it.second->update();
	}
}


std::shared_ptr<CameraComponent> ComponentController::getCamera() {
	if(components.find("Camera") == components.end()) {
		std::cout << "This entity doesn't have a Camera component\n";
		return nullptr;
	}
	return std::static_pointer_cast<CameraComponent>(components["Camera"]);
}


std::shared_ptr<GeometryComponent> ComponentController::getGeometry() {
	if(components.find("Geometry") == components.end()) {
		std::cout << "This entity doesn't have a Geometry component\n";
		return nullptr;
	}
	return std::static_pointer_cast<GeometryComponent>(components["Geometry"]);
}


std::shared_ptr<PhysicsComponent> ComponentController::getPhysics() {
	if(components.find("Physics") == components.end()) {
		std::cout << "This entity doesn't have a Physics component\n";
		return nullptr;
	}
	return std::static_pointer_cast<PhysicsComponent>(components["Physics"]);
}


std::shared_ptr<UserInputComponent> ComponentController::getUserInput() {
	if(components.find("UserInput") == components.end()) {
		std::cout << "This entity doesn't have a UserInput component\n";
		return nullptr;
	}
	return std::static_pointer_cast<UserInputComponent>(components["UserInput"]);
}
