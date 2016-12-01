#ifndef _GEPPETTO_COMPONENT_CONTROLLER_H_
#define _GEPPETTO_COMPONENT_CONTROLLER_H_

#include <string>
#include <map>
#include <memory>

#include "component.h"

class CameraComponent;
class GeometryComponent;
class PhysicsComponent;
class UserInputComponent;
class Entity;

class ComponentController
{
public:
	Entity& entity;
	
	ComponentController(Entity& e);
	~ComponentController();
	
	void add(const Component::Type type);
	bool isEnabled(const Component::Type type);
	void remove(const Component::Type type);
	void updateAll();
	
	std::shared_ptr<CameraComponent> getCamera();
	std::shared_ptr<GeometryComponent> getGeometry();
	std::shared_ptr<PhysicsComponent> getPhysics();
	std::shared_ptr<UserInputComponent> getUserInput();

private:
	std::map<Component::Type, std::shared_ptr<Component>> components;
};

#endif
