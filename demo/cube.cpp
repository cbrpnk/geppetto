#include "cube.h"


Cube::Cube(std::string name) :
Entity::Entity(name, "Cube"),
xRotationSpeed(0),
yRotationSpeed(0),
zRotationSpeed(0)
{
    //xRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
    yRotationSpeed = 2.0f;// Geppetto::Math::RandomFloat(-5.0f, 5.0f);
    //zRotationSpeed = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
    Rotate(60.0f, 0.0f, 20.0f);
    
    //position.x = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
    //position.y = Geppetto::Math::RandomFloat(-5.0f, 5.0f);
    //position.z = Geppetto::Math::RandomFloat(-50.0f, 50.0f);
    
    AddComponent(Geppetto::Component::Type::Physics);
    physics->SetFrictionCoefficient(0.15f);
    
    AddComponent(Geppetto::Component::Type::Mesh);
    mesh->LoadOBJFile("models/", "planet.obj", true);
    //mesh->Load(Geppetto::Component::Mesh::CubeIndex,
    //           Geppetto::Component::Mesh::CubeVertices,
    //           Geppetto::Component::Mesh::CubeNormals,
    //           Geppetto::Component::Mesh::CubeColors);
    
    AddComponent(Geppetto::Component::Type::Shader);
    shader->CreateShader("shaders/cube.vertex", "shaders/cube.fragment");
    shader->addUniform(&position, Geppetto::Component::Shader::UniformType::Float3, "pos");
}


Cube::~Cube()
{}


void Cube::Update()
{
    Rotate(xRotationSpeed, yRotationSpeed, zRotationSpeed);
}
