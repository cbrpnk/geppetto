#include "cube.h"


Cube::Cube(std::string name) :
GEntity::GEntity(name, "Cube"),
xRotationSpeed(0),
yRotationSpeed(0),
zRotationSpeed(0)
{}


Cube::~Cube()
{}


void Cube::load()
{
	xRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	yRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	zRotationSpeed = Gmath::randomFloat(-5.0f, 5.0f);
	
	position.x = Gmath::randomFloat(-50.0f, 50.0f);
	position.y = Gmath::randomFloat(-5.0f, 5.0f);
	position.z = Gmath::randomFloat(-50.0f, 50.0f);
	
	addGComponent(GComponent::Type::GPhysics);
	getGPhysics()->setFrictionCoefficient(0.15f);
	addGComponent(GComponent::Type::GGeometry);
	getGGeometry()->loadVertices(GGeometryComponent::Cube);
	getGGeometry()->setType(GGeometryComponent::Type::Quads);
}


void Cube::update()
{
	rotate(xRotationSpeed, yRotationSpeed, zRotationSpeed);
}
