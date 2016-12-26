#include "cube.h"


Cube::Cube(std::string name) :
Entity::Entity(name, "Cube"),
xRotationSpeed(0),
yRotationSpeed(0),
zRotationSpeed(0)
{}


Cube::~Cube()
{}


void Cube::Load()
{
	xRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	yRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	zRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	
	position.x = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
	position.y = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	position.z = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
	
	AddComponent(Geppetto::Component::Type::Physics);
	GetPhysics()->SetFrictionCoefficient(0.15f);
	AddComponent(Geppetto::Component::Type::Geometry);
	GetGeometry()->LoadVertices(Geppetto::Component::Geometry::Cube);
	GetGeometry()->SetType(Geppetto::Component::Geometry::Type::Quads);
}


void Cube::Update()
{
	Rotate(xRotationSpeed, yRotationSpeed, zRotationSpeed);
}
