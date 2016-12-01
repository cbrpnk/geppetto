#include "entity.h"
#include "component.h"
#include "physics_component.h"


PhysicsComponent::PhysicsComponent(Entity& e) : Component(e)
{
	acceleration = Vec3(0.0f, 0.0f, 0.0f);
	velocity = Vec3(0.0f, 0.0f, 0.0f);
	friction_coefficient = 0.0f;
}


PhysicsComponent::~PhysicsComponent()
{}


Vec3 PhysicsComponent::getAcceleration()
{
	return acceleration;
}


float PhysicsComponent::getFrictionCoefficient()
{
	return friction_coefficient;
}


Vec3 PhysicsComponent::getVelocity()
{
	return velocity;
}

void PhysicsComponent::setAcceleration(const Vec3 a)
{
	acceleration = a;
}


void PhysicsComponent::setFrictionCoefficient(const float f)
{
	friction_coefficient = f;
}


void PhysicsComponent::setVelocity(const Vec3 v)
{
	velocity = v;
}


void PhysicsComponent::update()
{
	acceleration *= 1 - friction_coefficient;
	velocity += acceleration - (velocity * friction_coefficient);
	entity.position += velocity;
}
