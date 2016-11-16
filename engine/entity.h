#ifndef _ENGINE_ENTITY_H_
#define _ENGINE_ENTITY_H_

#include <memory>
#include <string>
#include <map>

#include "component_controller.h"
#include "../lib/vec3.h"
#include "../lib/mat4.h"


class Entity {
public:
	std::string name;
	Vec3 position;
	Vec3 forward;
	Vec3 up;
	ComponentController components;
	
	Entity();
	
	Mat4 getReferenceFrame() const;
	void placeAt(const float x, const float y, const float z);
	void rotate(const float x, const float y, const float z);
	void update();
private:
	const static std::string base_name;
	static int n_entities;
};

#endif
