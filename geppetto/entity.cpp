#include <iostream>
#include <string>
#include <algorithm>

#include "entity.h"
#include "game.h"
#include "stage.h"
#include "math/math.h"

namespace Geppetto {

const std::string Entity::defaultName = "Entity";
int Entity::nEntities = 0;


Entity::Entity(std::string n, std::string t) :
active(true),
name(n),
type(t),
position(Math::Vec3(0, 0, 0)),
forward(Math::Vec3(0, 0, 1)),
up(Math::Vec3(0, 1, 0)),
game(Game::GetInstance()),
stage(*(Game::GetInstance().GetActiveStage())),
camera(nullptr),
mesh(nullptr),
physics(nullptr),
shader(nullptr),
userInput(nullptr)
{
    stage.AddEntity(this);
}


Entity::~Entity()
{
    if(camera) {
        RemoveComponent(Component::Type::Camera);
    }
    if(mesh) {
        RemoveComponent(Component::Type::Mesh);
    }
    if(physics) {
        RemoveComponent(Component::Type::Physics);
    }
    if(shader) {
        RemoveComponent(Component::Type::Shader);
    }
    if(userInput) {
        RemoveComponent(Component::Type::UserInput);
    }
    
    stage.RemoveEntity(name);
}


void Entity::Update()
{}


void Entity::UpdateEntity()
{
    if(camera) {
        camera->Update();
    }
    if(mesh) {
        mesh->Update();
    }
    if(physics) {
        physics->Update();
    }
    if(shader) {
        shader->Update();
    }
    if(userInput) {
        userInput->Update();
    }
    
    Update();
}


void Entity::PlaceAt(const float x, const float y, const float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}


Math::Mat4 Entity::GetReferenceFrame() const
{
    Math::Vec4 xAxis(Math::Vec4(up).Cross(forward));
    Math::Vec4 yAxis(up);
    Math::Vec4 zAxis(forward);
    Math::Mat4 rotation;
    rotation.Identity();
    rotation[0] = xAxis;
    rotation[1] = yAxis;
    rotation[2] = zAxis;
    
    Math::Mat4 translation;
    translation.Identity();
    translation[3] = Math::Vec4(position.x, position.y, position.z, 1);
    
    return translation * rotation;
}


Game& Entity::GetGame() const
{
    return game;
}


Stage& Entity::GetStage() const
{
    return stage;
}


void Entity::Rotate(const float x, const float y, const float z)
{
    Math::Mat4 ref = GetReferenceFrame();
    ref.Rotate(x, y, z);
    
    forward = Math::Vec3(ref[2].x, ref[2].y, ref[2].z);
    up      = Math::Vec3(ref[1].x, ref[1].y, ref[1].z);
    
    forward.Normalize();
    up.Normalize();
}


void Entity::AddComponent(const Component::Type type)
{
    if(!HasComponent(type)) {
        if(type == Component::Type::Camera) {
            camera = new Component::Camera(*this);
        } else if(type == Component::Type::Mesh) {
            mesh = new Component::Mesh(*this);
        } else if(type == Component::Type::Physics) {
            physics = new Component::Physics(*this);
        } else if(type == Component::Type::Shader) {
            shader = new Component::Shader(*this);
        } else if(type == Component::Type::UserInput) {
            userInput = new Component::UserInput(*this);
        }
    }
}


bool Entity::HasComponent(const Component::Type type) const
{
    if(type == Component::Type::Camera && camera) {
        return true;
    } else if(type == Component::Type::Mesh && mesh) {
        return true;
    } else if(type == Component::Type::Physics && physics) {
        return true;
    } else if(type == Component::Type::Shader && shader) {
        return true;
    } else if(type == Component::Type::UserInput && userInput) {
        return true;
    }
    
    return false;
}


void Entity::RemoveComponent(const Component::Type type)
{
    if(type == Component::Type::Camera && camera) {
        delete(camera);
        camera = nullptr;
    } else if(type == Component::Type::Mesh && mesh) {
        delete(mesh);
        mesh = nullptr;
    } else if(type == Component::Type::Physics && physics) {
        delete(physics);
        physics = nullptr;
    } else if(type == Component::Type::Shader && shader) {
        delete(shader);
        shader = nullptr;
    } else if(type == Component::Type::UserInput && userInput) {
        delete(userInput);
        userInput = nullptr;
    }
}


Component::Camera* Entity::GetCamera() const
{
    if(camera) {
        return camera;
    }
    return nullptr;
}


Component::Mesh* Entity::GetMesh() const
{
    if(mesh) {
        return mesh;
    }
    return nullptr;
}


Component::Physics* Entity::GetPhysics() const
{
    if(physics) {
        return physics;
    }
    return nullptr;
}

Component::Shader* Entity::GetShader() const
{
    if(shader) {
        return shader;
    }
    return nullptr;
}
    

Component::UserInput* Entity::GetUserInput()const
{
    if(userInput) {
        return userInput;
    }
    return nullptr;
}

} // namespace Geppetto
