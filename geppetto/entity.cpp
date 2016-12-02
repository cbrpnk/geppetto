#include <iostream>
#include <string>
#include <algorithm>

#include "entity.h"
#include "math/gmath.h"


const std::string Entity::default_name = "Entity";
int Entity::n_entities = 0;


Entity::Entity(Stage& parentStage) : active(true),
	name(default_name + std::to_string(n_entities++)),
	position(Vec3(0, 0, 0)),
	forward(Vec3(0, 0, 1)),
	up(Vec3(0, 1, 0)),
	customClass(nullptr),
	stage(parentStage),
	camera(nullptr),
	geometry(nullptr),
	physics(nullptr),
	userInput(nullptr)
{}


Entity::~Entity()
{
	if(customClass) {
		delete(customClass);
	}
	if(camera) {
		delete(camera);
	}
	if(geometry) {
		delete(geometry);
	}
	if(physics) {
		delete(physics);
	}
	if(userInput) {
		delete(userInput);
	}
}


void Entity::addCustomClass(CustomClass* const c)
{
	customClass = c;
}


void Entity::placeAt(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}


Mat4 Entity::getReferenceFrame() const
{
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

Stage& Entity::getStage() const
{
	return stage;
}


void Entity::load()
{
	if(customClass) {
		customClass->load(this);
	}
}


void Entity::rotate(const float x, const float y, const float z)
{
	Mat4 ref = getReferenceFrame();
	ref.rotate(x, y, z);
	
	forward = Vec3(ref[2].x, ref[2].y, ref[2].z);
	up      = Vec3(ref[1].x, ref[1].y, ref[1].z);
	
	forward.normalize();
	up.normalize();
}


void Entity::update()
{
	if(customClass) {
		customClass->update(this);
	}
	if(camera) {
		camera->update();
	}
	if(geometry) {
		geometry->update();
	}
	if(physics) {
		physics->update();
	}
	if(userInput) {
		userInput->update();
	}
	
}

void Entity::addComponent(const Component::Type type)
{
	if(!hasComponent(type)) {
		if(type == Component::Type::Camera) {
			camera = new CameraComponent(*this);
		} else if(type == Component::Type::Geometry) {
			geometry = new GeometryComponent(*this);
		} else if(type == Component::Type::Physics) {
			physics = new PhysicsComponent(*this);
		} else if(type == Component::Type::UserInput) {
			userInput = new UserInputComponent(*this);
		}
	}
}


bool Entity::hasComponent(const Component::Type type) const
{
	if(type == Component::Type::Camera && camera) {
		return true;
	} else if(type == Component::Type::Geometry && geometry) {
		return true;
	} else if(type == Component::Type::Physics && physics) {
		return true;
	} else if(type == Component::Type::UserInput && userInput) {
		return true;
	}
	
	return false;
}


void Entity::removeComponent(const Component::Type type)
{
	if(type == Component::Type::Camera && camera) {
		delete(camera);
		camera = nullptr;
	} else if(type == Component::Type::Geometry && geometry) {
		delete(geometry);
		geometry = nullptr;
	} else if(type == Component::Type::Physics && physics) {
		delete(physics);
		physics = nullptr;
	} else if(type == Component::Type::UserInput && userInput) {
		delete(userInput);
		userInput = nullptr;
	}
}


CameraComponent* Entity::getCamera() const
{
	return camera;
}


GeometryComponent* Entity::getGeometry() const
{
	return geometry;
}


PhysicsComponent* Entity::getPhysics() const
{
	return physics;
}
	

UserInputComponent* Entity::getUserInput()const
{
	return userInput;
}
