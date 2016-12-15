#include "../geppetto/geppetto.h"
#include "player.h"


Player::Player() :
GEntity::GEntity("Player", "Player")
{
	movement_acceleration = 0.003f;
	rotation_speed = 0.09f;
}

Player::~Player()
{}


void Player::load()
{
	addComponent(Component::Type::Physics);
	physics->setFrictionCoefficient(0.15f);
	
	addComponent(Component::Type::Camera);
	camera->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	
	addComponent(Component::Type::UserInput);
	
	gStage.setCameraGEntity(this);
}


void Player::update()
{
	if(userInput->keyPressed(GLFW_KEY_W)) {
		physics->setAcceleration(
			physics->getAcceleration() +
			forward *
			movement_acceleration);
	}
	if(userInput->keyPressed(UserInputComponent::KEY_A)) {
		getPhysics()->setAcceleration(physics->getAcceleration() +
			Vec3(forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			-movement_acceleration);
	}
	if(userInput->keyPressed(UserInputComponent::KEY_S)) {
		getPhysics()->setAcceleration(physics->getAcceleration() +
			forward *
			-movement_acceleration);
	}
	if(userInput->keyPressed(UserInputComponent::KEY_D)) {
		physics->setAcceleration(physics->getAcceleration() +
			Vec3(forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			movement_acceleration);
	}
	if(userInput->keyPressed(UserInputComponent::KEY_ESCAPE)) {
		gGame.shutdown();
	}
	
	rotate(userInput->getMouseYMovement() * -rotation_speed,
		userInput->getMouseXMovement() * rotation_speed, 0.0f);
}
