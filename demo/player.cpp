#include "../geppetto/geppetto.h"
#include "player.h"


Player::Player()
{
	movement_acceleration = 0.003f;
	rotation_speed = 0.09f;
}

Player::~Player()
{}


void Player::load(Entity* entity)
{
	entity->addComponent(Component::Type::Physics);
	entity->getPhysics()->setFrictionCoefficient(0.15f);
	entity->addComponent(Component::Type::Camera);
	entity->getCamera()->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	entity->addComponent(Component::Type::UserInput);
}


void Player::update(Entity* entity)
{
	if(entity->getUserInput()->keyPressed(GLFW_KEY_W)) {
		entity->getPhysics()->setAcceleration(
			entity->getPhysics()->getAcceleration() +
			entity->forward *
			movement_acceleration);
	}
	if(entity->getUserInput()->keyPressed(UserInputComponent::KEY_A)) {
		entity->getPhysics()->setAcceleration(entity->getPhysics()->getAcceleration() +
			Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			-movement_acceleration);
	}
	if(entity->getUserInput()->keyPressed(UserInputComponent::KEY_S)) {
		entity->getPhysics()->setAcceleration(entity->getPhysics()->getAcceleration() +
			entity->forward *
			-movement_acceleration);
	}
	if(entity->getUserInput()->keyPressed(UserInputComponent::KEY_D)) {
		entity->getPhysics()->setAcceleration(entity->getPhysics()->getAcceleration() +
			Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			movement_acceleration);
	}
	if(entity->getUserInput()->keyPressed(UserInputComponent::KEY_ESCAPE)) {
		entity->getStage().getGame().shutdown();
	}
	
	entity->rotate(entity->getUserInput()->getMouseYMovement() * -rotation_speed,
		entity->getUserInput()->getMouseXMovement() * rotation_speed, 0.0f);
}
