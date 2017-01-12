#include "../geppetto/geppetto.h"
#include "player.h"


Player::Player() :
Entity::Entity("Player", "Player")
{
    movement_acceleration = 0.003f;
    rotation_speed = 0.09f;
    zoomLevel = 0;
    
    position.x = 0.0f;
    position.y = 5.0f;
    position.z = 0.0f;
    Rotate(45.0f, 0.0f, 0.0f);
    
    AddComponent(Geppetto::Component::Type::Physics);
    physics->SetFrictionCoefficient(0.15f);
    
    AddComponent(Geppetto::Component::Type::Camera);
    camera->SetPosition(Geppetto::Math::Vec3(0.0f, 0.0f, 0.0f));
    
    AddComponent(Geppetto::Component::Type::UserInput);
    
    stage.SetCameraEntity(this);
}


Player::~Player()
{}


void Player::Update()
{
    // Keyboard movement [WASD]
    if(userInput->KeyPressed(Geppetto::Component::UserInput::KEY_W)) {
        physics->SetAcceleration(
            physics->GetAcceleration() +
            Geppetto::Math::Vec3(0.0f, 0.0f, 5.0f) *
            movement_acceleration);
    }
    
    if(userInput->KeyPressed(Geppetto::Component::UserInput::KEY_A)) {
        physics->SetAcceleration(physics->GetAcceleration() +
            Geppetto::Math::Vec3(forward).Cross(Geppetto::Math::Vec3(0.0f, 5.0f, 0.0f)) *
            -movement_acceleration);
    }
    
    if(userInput->KeyPressed(Geppetto::Component::UserInput::KEY_S)) {
        physics->SetAcceleration(physics->GetAcceleration() +
            Geppetto::Math::Vec3(0.0f, 0.0f, 5.0f) *
            -movement_acceleration);
    }
    
    if(userInput->KeyPressed(Geppetto::Component::UserInput::KEY_D)) {
        physics->SetAcceleration(physics->GetAcceleration() +
            Geppetto::Math::Vec3(forward).Cross(Geppetto::Math::Vec3(0.0f, 5.0f, 0.0f)) *
            movement_acceleration);
    }
    
    // Close the game [ESCAPE]
    if(userInput->KeyPressed(Geppetto::Component::UserInput::KEY_ESCAPE)) {
        game.Shutdown();
    }
    
    // Zoom on scene [Mouse Scroll]
    int scroll = userInput->mouseState.yScroll;
    float zoom = (zoomLevel - scroll) * 0.1;
    zoomLevel = scroll;
    physics->SetAcceleration(physics->GetAcceleration() + (forward * -zoom));
}
