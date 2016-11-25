#include <iostream>
#include <string>
#include <algorithm>

#include "entity.h"
#include "component_controller.h"
#include "physics_component.h"
#include "../lib/gmath.h"


const std::string Entity::default_name = "Entity";
int Entity::n_entities = 0;


Entity::Entity(Scene* parentScene) : name(default_name + std::to_string(n_entities++)),
	position(Vec3(0, 0, 0)),
	forward(Vec3(0, 0, 1)),
	up(Vec3(0, 1, 0)),
	components(*this),
	customClass(nullptr),
	scene(parentScene)
{}


Entity::~Entity() {}


void Entity::addCustomClass(CustomClass* c) {
	customClass = c;
}


void Entity::placeAt(const float x, const float y, const float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}


Mat4 Entity::getReferenceFrame() const {
	Vec4 x_axis(Vec4(up).cross(forward));
	Vec4 y_axis(up);
	Vec4 z_axis(forward);
	Mat4 rotation;
	rotation.identity();
	rotation[0] = x_axis;
	rotation[1] = y_axis;
	rotation[2] = z_axis;
	
	Mat4 translation;
	translation.identity();
	translation[3] = Vec4(position.x, position.y, position.z, 1);
	
	return translation * rotation;
}


void Entity::rotate(const float x, const float y, const float z) {
	Mat4 ref = getReferenceFrame();
	ref.rotate(x, y, z);
	
	forward = Vec3(ref[2].x, ref[2].y, ref[2].z);
	up      = Vec3(ref[1].x, ref[1].y, ref[1].z);
	
	forward.normalize();
	up.normalize();
}


void Entity::update() {
	components.updateAll();
	if(customClass) {
		customClass->update(this);
	}
}
