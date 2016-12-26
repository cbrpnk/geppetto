#include "../entity.h"
#include "physics.h"

namespace Geppetto {
namespace Component {

Physics::Physics(Entity& e) : ComponentBase(e)
{
	acceleration = Math::Vec3(0.0f, 0.0f, 0.0f);
	velocity = Math::Vec3(0.0f, 0.0f, 0.0f);
	frictionCoefficient = 0.0f;
}


Physics::~Physics()
{}


Math::Vec3 Physics::GetAcceleration()
{
	return acceleration;
}


float Physics::GetFrictionCoefficient()
{
	return frictionCoefficient;
}


Math::Vec3 Physics::GetVelocity()
{
	return velocity;
}

void Physics::SetAcceleration(const Math::Vec3 a)
{
	acceleration = a;
}


void Physics::SetFrictionCoefficient(const float f)
{
	frictionCoefficient = f;
}


void Physics::SetVelocity(const Math::Vec3 v)
{
	velocity = v;
}


void Physics::Update()
{
	acceleration *= 1 - frictionCoefficient;
	velocity += acceleration - (velocity * frictionCoefficient);
	entity.position += velocity;
}

} // namespace Component
} // namespace Geppetto
