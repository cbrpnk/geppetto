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
	position.y = 25;
	rotate(45.0f, 0.0f, 0.0f);
	
	addGComponent(GComponent::Type::GPhysics);
	gPhysics->setFrictionCoefficient(0.15f);
	
	addGComponent(GComponent::Type::GCamera);
	gCamera->setPosition(GVec3(0.0f, 2.0f, 0.0f));
	
	addGComponent(GComponent::Type::GUserInput);
	
	gStage.setCameraGEntity(this);
}


void Player::update()
{
	// Keyboard movement (WASD)
	if(gUserInput->keyPressed(GLFW_KEY_W)) {
		gPhysics->setAcceleration(
			gPhysics->getAcceleration() +
			GVec3(0.0f, 0.0f, 5.0f) *
			movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_A)) {
		getGPhysics()->setAcceleration(gPhysics->getAcceleration() +
			GVec3(forward).cross(GVec3(0.0f, 5.0f, 0.0f)) *
			-movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_S)) {
		getGPhysics()->setAcceleration(gPhysics->getAcceleration() +
			GVec3(0.0f, 0.0f, 5.0f) *
			-movement_acceleration);
	}
	if(gUserInput->keyPressed(GUserInputComponent::KEY_D)) {
		gPhysics->setAcceleration(gPhysics->getAcceleration() +
			GVec3(forward).cross(GVec3(0.0f, 5.0f, 0.0f)) *
			movement_acceleration);
	}
	
	// Mouse zoom
	
	
	// Close the game
	if(gUserInput->keyPressed(GUserInputComponent::KEY_ESCAPE)) {
		gGame.shutdown();
	}
}


