#ifndef _GEPPETTO_ENTITY_H_
#define _GEPPETTO_ENTITY_H_

#include <memory>
#include <string>
#include <map>

//#include "component_controller.h"
#include "component.h"
#include "components/camera_component.h"
#include "components/geometry_component.h"
#include "components/physics_component.h"
#include "components/user_input_component.h"
#include "math/vec3.h"
#include "math/mat4.h"

class GStage;

class Entity
{
public:
	bool        active;
	std::string name;
	std::string type;
	Vec3        position;
	Vec3        forward;
	Vec3        up;
	
	Entity(std::string n, std::string t);
	virtual ~Entity();
	
	virtual void load();
	virtual void update();
	void loadEntity();
	void updateEntity();
	
	GGame&  getGGame() const;
	GStage& getGStage() const;
	Mat4   getReferenceFrame() const;
	void   placeAt(const float x, const float y, const float z);
	void   rotate(const float x, const float y, const float z);
	
	/* Deal With Components */
	void addComponent(const Component::Type type);
	bool hasComponent(const Component::Type type) const;
	void removeComponent(const Component::Type type);
	
	CameraComponent*    getCamera()    const;
	GeometryComponent*  getGeometry()  const;
	PhysicsComponent*   getPhysics()   const;
	UserInputComponent* getUserInput() const;
	
protected:
	const static        std::string default_name;
	static int          n_entities;
	
	GGame&               gGame;
	GStage&              gStage;
	
	CameraComponent*    camera;
	GeometryComponent*  geometry;
	PhysicsComponent*   physics;
	UserInputComponent* userInput;
};

#endif
