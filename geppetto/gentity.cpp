#include <iostream>
#include <string>
#include <algorithm>

#include "gentity.h"
#include "ggame.h"
#include "gstage.h"
#include "math/gmath.h"


const std::string GEntity::default_name = "GEntity";
int GEntity::n_gEntities = 0;


GEntity::GEntity(std::string n, std::string t) :
active(true),
name(n),
type(t),
position(Vec3(0, 0, 0)),
forward(Vec3(0, 0, 1)),
up(Vec3(0, 1, 0)),
gGame(GGame::getInstance()),
gStage(GGame::getInstance().getActiveGStage()),
camera(nullptr),
geometry(nullptr),
physics(nullptr),
userInput(nullptr)
{
	gStage.addGEntity(this);
}


GEntity::~GEntity()
{
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


void GEntity::load()
{}


void GEntity::update()
{}

void GEntity::loadGEntity()
{
	load();
}


void GEntity::updateGEntity()
{
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
	
	update();
}


void GEntity::placeAt(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}


Mat4 GEntity::getReferenceFrame() const
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


GGame& GEntity::getGGame() const
{
	return gGame;
}


GStage& GEntity::getGStage() const
{
	return gStage;
}


void GEntity::rotate(const float x, const float y, const float z)
{
	Mat4 ref = getReferenceFrame();
	ref.rotate(x, y, z);
	
	forward = Vec3(ref[2].x, ref[2].y, ref[2].z);
	up      = Vec3(ref[1].x, ref[1].y, ref[1].z);
	
	forward.normalize();
	up.normalize();
}


void GEntity::addComponent(const Component::Type type)
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


bool GEntity::hasComponent(const Component::Type type) const
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


void GEntity::removeComponent(const Component::Type type)
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


CameraComponent* GEntity::getCamera() const
{
	return camera;
}


GeometryComponent* GEntity::getGeometry() const
{
	return geometry;
}


PhysicsComponent* GEntity::getPhysics() const
{
	return physics;
}
	

UserInputComponent* GEntity::getUserInput()const
{
	return userInput;
}
