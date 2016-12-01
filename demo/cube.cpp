#include "cube.h"

Cube::Cube() : xRotationSpeed(0),
	yRotationSpeed(0),
	zRotationSpeed(0)
{}

Cube::~Cube()
{}

void Cube::load(Entity* entity)
{
	xRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	yRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	zRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	
	entity->position.x = Gmath::randomFloat(-50.0f, 50.0f);
	entity->position.y = Gmath::randomFloat(-5.0f, 5.0f);
	entity->position.z = Gmath::randomFloat(-50.0f, 50.0f);
	
	entity->components.add(Component::Type::Physics);
	entity->components.getPhysics()->setFrictionCoefficient(0.15f);
	entity->components.add(Component::Type::Geometry);
	entity->components.getGeometry()->loadVertices(GeometryComponent::Cube);
	entity->components.getGeometry()->setType(GeometryComponent::Type::Quads);
}

void Cube::update(Entity* entity)
{
	entity->rotate(xRotationSpeed, yRotationSpeed, zRotationSpeed);
}
