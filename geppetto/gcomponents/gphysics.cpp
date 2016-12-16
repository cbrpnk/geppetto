#include "../gentity.h"
#include "gphysics.h"


GPhysicsComponent::GPhysicsComponent(GEntity& e) : GComponent(e)
{
	acceleration = GVec3(0.0f, 0.0f, 0.0f);
	velocity = GVec3(0.0f, 0.0f, 0.0f);
	friction_coefficient = 0.0f;
}


GPhysicsComponent::~GPhysicsComponent()
{}


GVec3 GPhysicsComponent::getAcceleration()
{
	return acceleration;
}


float GPhysicsComponent::getFrictionCoefficient()
{
	return friction_coefficient;
}


GVec3 GPhysicsComponent::getVelocity()
{
	return velocity;
}

void GPhysicsComponent::setAcceleration(const GVec3 a)
{
	acceleration = a;
}


void GPhysicsComponent::setFrictionCoefficient(const float f)
{
	friction_coefficient = f;
}


void GPhysicsComponent::setVelocity(const GVec3 v)
{
	velocity = v;
}


void GPhysicsComponent::update()
{
	acceleration *= 1 - friction_coefficient;
	velocity += acceleration - (velocity * friction_coefficient);
	gEntity.position += velocity;
}
