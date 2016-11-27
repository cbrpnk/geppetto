#include "GLFW/glfw3.h"
#include "../geppetto/geppetto.h"
#include "player.h"

Player::Player() {}
Player::~Player() {}

void Player::load() {}

void Player::update(Entity* entity) {
	float movement_acceleration = 0.003f;
	float rotation_speed = 0.09f;
	std::shared_ptr<UserInputComponent> input = entity->components.getUserInput();	
	std::shared_ptr<PhysicsComponent> physics = entity->components.getPhysics();
	
	if(input->keyPressed(GLFW_KEY_W)) {
		physics->setAcceleration(physics->getAcceleration() + entity->forward * movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_A)) {
		physics->setAcceleration(physics->getAcceleration() + Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * -movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_S)) {
		physics->setAcceleration(physics->getAcceleration() + entity->forward * -movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_D)) {
		physics->setAcceleration(physics->getAcceleration() += Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_ESCAPE)) {
		entity->scene->getGame()->shutdown();
	}
	
	entity->rotate(-input->getMouseYMovement() * rotation_speed, input->getMouseXMovement() * rotation_speed, 0.0f);

}
