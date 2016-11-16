#ifndef _ENGINE_COMPONENT_CONTROLLER_H_
#define _ENGINE_COMPONENT_CONTROLLER_H_

#include <string>
#include <map>
#include <memory>

class Component;
class CameraComponent;
class GeometryComponent;
class LogicComponent;
class PhysicsComponent;
class UserInputComponent;
class Entity;

class ComponentController {
public:
	Entity& entity;
	
	ComponentController(Entity& e);
	~ComponentController();
	
	void add(std::string name);
	bool isEnabled(std::string name);
	void remove(std::string name);
	void updateAll();
	
	std::shared_ptr<CameraComponent> getCamera();
	std::shared_ptr<GeometryComponent> getGeometry();
	std::shared_ptr<LogicComponent> getLogic();
	std::shared_ptr<PhysicsComponent> getPhysics();
	std::shared_ptr<UserInputComponent> getUserInput();

private:
	std::map<std::string, std::shared_ptr<Component>> components;
};

#endif
