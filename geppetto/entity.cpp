#include <iostream>
#include <string>
#include <algorithm>

#include "entity.h"
#include "game.h"
#include "stage.h"
#include "math/math.h"

namespace Geppetto {

const std::string Entity::defaultName = "Entity";
int Entity::nGEntities = 0;


Entity::Entity(std::string n, std::string t) :
active(true),
name(n),
type(t),
position(Math::Vec3(0, 0, 0)),
forward(Math::Vec3(0, 0, 1)),
up(Math::Vec3(0, 1, 0)),
game(Game::GetInstance()),
stage(Game::GetInstance().GetActiveStage()),
camera(nullptr),
geometry(nullptr),
physics(nullptr),
userInput(nullptr)
{
	stage.AddEntity(this);
}


Entity::~Entity()
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


void Entity::Load()
{}


void Entity::Update()
{}


void Entity::LoadEntity()
{
	Load();
}


void Entity::UpdateEntity()
{
	if(camera) {
		camera->Update();
	}
	if(geometry) {
		geometry->Update();
	}
	if(physics) {
		physics->Update();
	}
	if(userInput) {
		userInput->Update();
	}
	
	Update();
}


void Entity::PlaceAt(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}


Math::Mat4 Entity::GetReferenceFrame() const
{
	Math::Vec4 xAxis(Math::Vec4(up).Cross(forward));
	Math::Vec4 yAxis(up);
	Math::Vec4 zAxis(forward);
	Math::Mat4 rotation;
	rotation.Identity();
	rotation[0] = xAxis;
	rotation[1] = yAxis;
	rotation[2] = zAxis;
	
	Math::Mat4 translation;
	translation.Identity();
	translation[3] = Math::Vec4(position.x, position.y, position.z, 1);
	
	return translation * rotation;
}


Game& Entity::GetGame() const
{
	return game;
}


Stage& Entity::GetStage() const
{
	return stage;
}


void Entity::Rotate(const float x, const float y, const float z)
{
	Math::Mat4 ref = GetReferenceFrame();
	ref.Rotate(x, y, z);
	
	forward = Math::Vec3(ref[2].x, ref[2].y, ref[2].z);
	up      = Math::Vec3(ref[1].x, ref[1].y, ref[1].z);
	
	forward.Normalize();
	up.Normalize();
}


void Entity::AddComponent(const Component::Type type)
{
	if(!HasComponent(type)) {
		if(type == Component::Type::Camera) {
			camera = new Component::Camera(*this);
		} else if(type == Component::Type::Geometry) {
			geometry = new Component::Geometry(*this);
		} else if(type == Component::Type::Physics) {
			physics = new Component::Physics(*this);
		} else if(type == Component::Type::UserInput) {
			userInput = new Component::UserInput(*this);
		}
	}
}


bool Entity::HasComponent(const Component::Type type) const
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


void Entity::RemoveComponent(const Component::Type type)
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


Component::Camera* Entity::GetCamera() const
{
	if(camera) {
		return camera;
	}
	return nullptr;
}


Component::Geometry* Entity::GetGeometry() const
{
	if(geometry) {
		return geometry;
	}
	return nullptr;
}


Component::Physics* Entity::GetPhysics() const
{
	if(physics) {
		return physics;
	}
	return nullptr;
}
	

Component::UserInput* Entity::GetUserInput()const
{
	if(userInput) {
		return userInput;
	}
	return nullptr;
}

} // namespace Geppetto
