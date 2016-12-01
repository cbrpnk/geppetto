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
	entity->components.add(Component::Type::Physics);
	entity->components.getPhysics()->setFrictionCoefficient(0.15f);
	entity->components.add(Component::Type::Camera);
	entity->components.getCamera()->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	entity->components.add(Component::Type::UserInput);
}


void Player::update(Entity* entity)
{
	std::shared_ptr<UserInputComponent> input = entity->components.getUserInput();	
	std::shared_ptr<PhysicsComponent> physics = entity->components.getPhysics();
	
	if(input->keyPressed(GLFW_KEY_W)) {
		physics->setAcceleration(physics->getAcceleration() + entity->forward * movement_acceleration);
	}
	if(input->keyPressed(UserInputComponent::KEY_A)) {
		physics->setAcceleration(physics->getAcceleration() + Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * -movement_acceleration);
	}
	if(input->keyPressed(UserInputComponent::KEY_S)) {
		physics->setAcceleration(physics->getAcceleration() + entity->forward * -movement_acceleration);
	}
	if(input->keyPressed(UserInputComponent::KEY_D)) {
		physics->setAcceleration(physics->getAcceleration() + Vec3(entity->forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * movement_acceleration);
	}
	if(input->keyPressed(UserInputComponent::KEY_ESCAPE)) {
		entity->stage->getGame()->shutdown();
	}
	
	entity->rotate(-input->getMouseYMovement() * rotation_speed, input->getMouseXMovement() * rotation_speed, 0.0f);

}
