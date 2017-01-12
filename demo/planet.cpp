#include "planet.h"


Planet::Planet(std::string name) :
Entity::Entity(name, "Planet"),
rotationSpeed(0)
{
    Rotate(60.0f, 0.0f, 20.0f);
    rotationSpeed = 1.0f;
    position = Geppetto::Math::Vec3(0.0f, 0.0f, 0.0f);
    
    AddComponent(Geppetto::Component::Type::Physics);
    physics->SetFrictionCoefficient(0.15f);
    
    AddComponent(Geppetto::Component::Type::Mesh);
    mesh->LoadOBJFile("models/", "planet.obj", true);
    
    AddComponent(Geppetto::Component::Type::Shader);
    shader->CreateShader("shaders/cube.vertex", "shaders/cube.fragment");
    shader->addUniform(&position, Geppetto::Component::Shader::UniformType::Float3, "pos");
}


Planet::~Planet()
{}


void Planet::Update()
{
    Rotate(0.0f, rotationSpeed, 0.0f);
}
