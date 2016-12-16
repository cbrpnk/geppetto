#include "../gentity.h"
#include "g_physics.h"


GPhysicsComponent::GPhysicsComponent(GEntity& e) : GComponent(e)
{
	acceleration = Vec3(0.0f, 0.0f, 0.0f);
	velocity = Vec3(0.0f, 0.0f, 0.0f);
	friction_coefficient = 0.0f;
}


GPhysicsComponent::~GPhysicsComponent()
{}


Vec3 GPhysicsComponent::getAcceleration()
{
	return acceleration;
}


float GPhysicsComponent::getFrictionCoefficient()
{
	return friction_coefficient;
}


Vec3 GPhysicsComponent::getVelocity()
{
	return velocity;
}

void GPhysicsComponent::setAcceleration(const Vec3 a)
{
	acceleration = a;
}


void GPhysicsComponent::setFrictionCoefficient(const float f)
{
	friction_coefficient = f;
}


void GPhysicsComponent::setVelocity(const Vec3 v)
{
	velocity = v;
}


void GPhysicsComponent::update()
{
	acceleration *= 1 - friction_coefficient;
	velocity += acceleration - (velocity * friction_coefficient);
	gEntity.position += velocity;
}
