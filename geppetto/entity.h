#ifndef _GEPPETTO_ENTITY_H_
#define _GEPPETTO_ENTITY_H_

#include <memory>
#include <string>
#include <map>

#include "component_controller.h"
#include "custom_class.h"
#include "math/vec3.h"
#include "math/mat4.h"

class Stage;

class Entity {
public:
	std::string name;
	Vec3 position;
	Vec3 forward;
	Vec3 up;
	ComponentController components;
	CustomClass* customClass;
	Stage* stage;
	
	Entity(Stage* parentStage);
	~Entity();
	
	void addCustomClass(CustomClass* c);
	Mat4 getReferenceFrame() const;
	void placeAt(const float x, const float y, const float z);
	void rotate(const float x, const float y, const float z);
	void update();
	
private:
	const static std::string default_name;
	static int n_entities;
};

#endif
