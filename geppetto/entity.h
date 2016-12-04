#ifndef _GEPPETTO_ENTITY_H_
#define _GEPPETTO_ENTITY_H_

#include <memory>
#include <string>
#include <map>

//#include "component_controller.h"
#include "component.h"
#include "camera_component.h"
#include "geometry_component.h"
#include "physics_component.h"
#include "user_input_component.h"
#include "custom_class.h"
#include "math/vec3.h"
#include "math/mat4.h"

class Stage;

class Entity
{
public:
	bool                active;
	std::string         name;
	Vec3                position;
	Vec3                forward;
	Vec3                up;
	
	Entity(Stage& parentStage);
	~Entity();
	
	// TODO:
	// removeCustomClass()
	// getCustomClass()
	
	void   addCustomClass(CustomClass* const c);
	Mat4   getReferenceFrame() const;
	Stage& getStage() const;
	void   load();
	void   placeAt(const float x, const float y, const float z);
	void   rotate(const float x, const float y, const float z);
	void   update();
	
	/* Deal With Components */
	void addComponent(const Component::Type type);
	bool hasComponent(const Component::Type type) const;
	void removeComponent(const Component::Type type);
	
	CameraComponent*    getCamera() const;
	GeometryComponent*  getGeometry() const;
	PhysicsComponent*   getPhysics() const;
	UserInputComponent* getUserInput()const ;
	
private:
	const static        std::string default_name;
	static int          n_entities;
	
	CustomClass*        customClass;
	Stage&              stage;
	
	CameraComponent*    camera;
	GeometryComponent*  geometry;
	PhysicsComponent*   physics;
	UserInputComponent* userInput;
};

#endif
