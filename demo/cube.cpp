#include "cube.h"


Cube::Cube(std::string name) :
Entity::Entity(name, "Cube"),
xRotationSpeed(0),
yRotationSpeed(0),
zRotationSpeed(0)
{
	xRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	yRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	zRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	
	position.x = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
	position.y = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
	position.z = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
	
	AddComponent(Geppetto::Component::Type::Physics);
	physics->SetFrictionCoefficient(0.15f);
	
	AddComponent(Geppetto::Component::Type::Geometry);
	geometry->LoadVertices(Geppetto::Component::Geometry::Cube);
	geometry->SetType(Geppetto::Component::Geometry::Type::Quads);
	
	AddComponent(Geppetto::Component::Type::Shader);
	shader->CreateShader("shaders/cube.vertex", "shaders/cube.fragment");
}


Cube::~Cube()
{}


void Cube::Update()
{
	Rotate(xRotationSpeed, yRotationSpeed, zRotationSpeed);
}
