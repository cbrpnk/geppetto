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
	addGComponent(GComponent::Type::GPhysics);
	gPhysics->setFrictionCoefficient(0.15f);
	
	addGComponent(GComponent::Type::GCamera);
	gCamera->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	
	addGComponent(GComponent::Type::GUserInput);
	
	gStage.setCameraGEntity(this);
}


void Player::update()
{
	if(gUserInput->keyPressed(GLFW_KEY_W)) {
		gPhysics->setAcceleration(
			gPhysics->getAcceleration() +
			forward *
			movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_A)) {
		getGPhysics()->setAcceleration(gPhysics->getAcceleration() +
			Vec3(forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			-movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_S)) {
		getGPhysics()->setAcceleration(gPhysics->getAcceleration() +
			forward *
			-movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_D)) {
		gPhysics->setAcceleration(gPhysics->getAcceleration() +
			Vec3(forward).cross(Vec3(0.0f, 1.0f, 0.0f)) *
			movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_ESCAPE)) {
		gGame.shutdown();
	}
	
	rotate(gUserInput->getMouseYMovement() * -rotation_speed,
		gUserInput->getMouseXMovement() * rotation_speed, 0.0f);
}
