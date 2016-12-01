#include <iostream>
#include <memory>

#include "component.h"
#include "component_controller.h"
#include "camera_component.h"
#include "geometry_component.h"
#include "physics_component.h"
#include "user_input_component.h"
#include "entity.h"


ComponentController::ComponentController(Entity& e) : entity(e)
{}


ComponentController::~ComponentController()
{}


void ComponentController::add(const Component::Type type)
{
	switch(type) {
	case Component::Type::Camera:
		components[type] = std::unique_ptr<Component> (new CameraComponent(entity));
		break;
	case Component::Type::Geometry:
		components[type] = std::unique_ptr<Component> (new GeometryComponent(entity));
		break;
	case Component::Type::Physics:
		components[type] = std::unique_ptr<Component> (new PhysicsComponent(entity));
		break;
	case Component::Type::UserInput:
		components[type] = std::unique_ptr<Component> (new UserInputComponent(entity));
		break;
	default:
		std::cout << "Invalid component type.\n";
		break;
	}
}


bool ComponentController::isEnabled(const Component::Type type)
{
	if(components.find(type) != components.end()) {
		return true;
	}
	return false;
}


void ComponentController::remove(const Component::Type type)
{
	if(components.find(type) == components.end()) {
		std::cout << "This entity doesn't have a this type of component\n";
	} else {
		components.erase(type);
	}
}


void ComponentController::updateAll()
{
	for(auto it : components) {
		it.second->update();
	}
}


std::shared_ptr<CameraComponent> ComponentController::getCamera()
{
	if(components.find(Component::Type::Camera) == components.end()) {
		std::cout << "This entity doesn't have a Camera component\n";
		return nullptr;
	}
	return std::static_pointer_cast<CameraComponent>(components[Component::Type::Camera]);
}


std::shared_ptr<GeometryComponent> ComponentController::getGeometry()
{
	if(components.find(Component::Type::Geometry) == components.end()) {
		std::cout << "This entity doesn't have a Geometry component\n";
		return nullptr;
	}
	return std::static_pointer_cast<GeometryComponent>(components[Component::Type::Geometry]);
}


std::shared_ptr<PhysicsComponent> ComponentController::getPhysics()
{
	if(components.find(Component::Type::Physics) == components.end()) {
		std::cout << "This entity doesn't have a Physics component\n";
		return nullptr;
	}
	return std::static_pointer_cast<PhysicsComponent>(components[Component::Type::Physics]);
}


std::shared_ptr<UserInputComponent> ComponentController::getUserInput()
{
	if(components.find(Component::Type::UserInput) == components.end()) {
		std::cout << "This entity doesn't have a UserInput component\n";
		return nullptr;
	}
	return std::static_pointer_cast<UserInputComponent>(components[Component::Type::UserInput]);
}
