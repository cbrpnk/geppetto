#include <iostream>
#include <string>
#include <algorithm>

#include "gentity.h"
#include "ggame.h"
#include "gstage.h"
#include "gmath/gmath.h"


const std::string GEntity::default_name = "GEntity";
int GEntity::n_gEntities = 0;


GEntity::GEntity(std::string n, std::string t) :
active(true),
name(n),
type(t),
position(GVec3(0, 0, 0)),
forward(GVec3(0, 0, 1)),
up(GVec3(0, 1, 0)),
gGame(GGame::getInstance()),
gStage(GGame::getInstance().getActiveGStage()),
gCamera(nullptr),
gGeometry(nullptr),
gPhysics(nullptr),
gUserInput(nullptr)
{
	gStage.addGEntity(this);
}


GEntity::~GEntity()
{
	if(gCamera) {
		delete(gCamera);
	}
	if(gGeometry) {
		delete(gGeometry);
	}
	if(gPhysics) {
		delete(gPhysics);
	}
	if(gUserInput) {
		delete(gUserInput);
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
	if(gCamera) {
		gCamera->update();
	}
	if(gGeometry) {
		gGeometry->update();
	}
	if(gPhysics) {
		gPhysics->update();
	}
	if(gUserInput) {
		gUserInput->update();
	}
	
	update();
}


void GEntity::placeAt(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}


GMat4 GEntity::getReferenceFrame() const
{
	GVec4 x_axis(GVec4(up).cross(forward));
	GVec4 y_axis(up);
	GVec4 z_axis(forward);
	GMat4 rotation;
	rotation.identity();
	rotation[0] = x_axis;
	rotation[1] = y_axis;
	rotation[2] = z_axis;
	
	GMat4 translation;
	translation.identity();
	translation[3] = GVec4(position.x, position.y, position.z, 1);
	
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
	GMat4 ref = getReferenceFrame();
	ref.rotate(x, y, z);
	
	forward = GVec3(ref[2].x, ref[2].y, ref[2].z);
	up      = GVec3(ref[1].x, ref[1].y, ref[1].z);
	
	forward.normalize();
	up.normalize();
}


void GEntity::addGComponent(const GComponent::Type type)
{
	if(!hasGComponent(type)) {
		if(type == GComponent::Type::GCamera) {
			gCamera = new GCameraComponent(*this);
		} else if(type == GComponent::Type::GGeometry) {
			gGeometry = new GGeometryComponent(*this);
		} else if(type == GComponent::Type::GPhysics) {
			gPhysics = new GPhysicsComponent(*this);
		} else if(type == GComponent::Type::GUserInput) {
			gUserInput = new GUserInputComponent(*this);
		}
	}
}


bool GEntity::hasGComponent(const GComponent::Type type) const
{
	if(type == GComponent::Type::GCamera && gCamera) {
		return true;
	} else if(type == GComponent::Type::GGeometry && gGeometry) {
		return true;
	} else if(type == GComponent::Type::GPhysics && gPhysics) {
		return true;
	} else if(type == GComponent::Type::GUserInput && gUserInput) {
		return true;
	}
	
	return false;
}


void GEntity::removeGComponent(const GComponent::Type type)
{
	if(type == GComponent::Type::GCamera && gCamera) {
		delete(gCamera);
		gCamera = nullptr;
	} else if(type == GComponent::Type::GGeometry && gGeometry) {
		delete(gGeometry);
		gGeometry = nullptr;
	} else if(type == GComponent::Type::GPhysics && gPhysics) {
		delete(gPhysics);
		gPhysics = nullptr;
	} else if(type == GComponent::Type::GUserInput && gUserInput) {
		delete(gUserInput);
		gUserInput = nullptr;
	}
}


GCameraComponent* GEntity::getGCamera() const
{
	return gCamera;
}


GGeometryComponent* GEntity::getGGeometry() const
{
	return gGeometry;
}


GPhysicsComponent* GEntity::getGPhysics() const
{
	return gPhysics;
}
	

GUserInputComponent* GEntity::getGUserInput()const
{
	return gUserInput;
}
