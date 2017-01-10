#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "components/camera.h"
#include "components/mesh.h"
#include "components/userinput.h"
#include "game.h"
#include "stage.h"

namespace Geppetto {

Game* Game::instance = nullptr;

Game::Game(std::string n, const int w, const int h) :
name(n),
window(nullptr),
width(w),
height(h),
activeStage(nullptr)
{
    instance = this;
}

Game::~Game()
{
    delete activeStage;
}


void Game::GlfwErrorCallback(int error, const char *desc)
{
    std::cout << "GLFW error: " << desc << std::endl;
}


Game& Game::GetInstance()
{
    return *instance;
}


bool Game::Init()
{
    glfwSetErrorCallback(GlfwErrorCallback);
        
    if(!glfwInit())
    {
        std::cout << "failed to initialize glfw" << std::endl;
        return false;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);  
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if(window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize glew" << std::endl;
        glfwTerminate();
        return false;
    }
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window, Component::UserInput::GlfwKeyCallback);
    glfwSetCursorPosCallback(window, Component::UserInput::GlfwMouseMoveCallback);
    glfwSetScrollCallback(window, Component::UserInput::GlfwMouseScrollCallback);
    glfwSetMouseButtonCallback(window, Component::UserInput::GlfwMouseButtonCallback);
    
    // Viewport and projection
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 1.0, 425.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glShadeModel(GL_FLAT); // GL_FLAT or GL_SMOOTH
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    return true;
}


void Game::Run()
{
    while(runGame) {
        glfwPollEvents();
        activeStage->UpdateStage();
        Render();
    }
    
    glfwTerminate();
}


void Game::Shutdown()
{
    runGame = false;
}


void Game::SetActiveStage(Stage* stage)
{
    activeStage = stage;
}


Stage* Game::GetActiveStage()
{
    return activeStage;
}


/* Private */
void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix();
        
        Entity* cameraEntity = activeStage->GetCameraEntity();
        if(!cameraEntity) exit(1);
        
        Math::Vec3 cameraPosition = cameraEntity->position + cameraEntity->GetCamera()->GetPosition();
        Math::Vec3 lookAt = cameraPosition + cameraEntity->forward;
        gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, lookAt.x, lookAt.y, lookAt.z, 0.0f, 1.0f, 0.0f);
        
        for(auto entityPair : activeStage->GetEntities()) {
            Entity* e = entityPair.second;
            
            // Check if Entity has a Mesh component
            if(e->active && e->HasComponent(Component::Type::Shader) &&
                                   e->HasComponent(Component::Type::Mesh)) {
                
                e->GetShader()->Use();
                
                glPushMatrix();
                    glMultMatrixf(e->GetReferenceFrame().ToArray());
                    
                    // Select the right type of Mesh
                    GLenum type;
                    switch(e->GetMesh()->GetType()) {
                    case Component::Mesh::Type::Points:
                        type = GL_POINTS;
                        break;
                    case Component::Mesh::Type::Lines:
                        type = GL_LINES;
                        break;
                    case Component::Mesh::Type::Triangles:
                        type = GL_TRIANGLES;
                        break;
                    case Component::Mesh::Type::Quads:
                        type = GL_QUADS;
                        break;
                    default:
                        type = GL_TRIANGLES;
                        break;
                    }
                    
                    glEnableClientState(GL_VERTEX_ARRAY);
                    glEnableClientState(GL_NORMAL_ARRAY);
                    
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (GLuint) e->GetMesh()->GetIndexBuffer());
                    
                    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) e->GetMesh()->GetVertexBuffer());
                    glVertexPointer(3, GL_FLOAT, 0, 0);
                    
                    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) e->GetMesh()->GetNormalBuffer());
                    glNormalPointer(GL_FLOAT, 0, 0);
                    
                    glDrawElements(type, e->GetMesh()->GetVertexCount(), GL_UNSIGNED_SHORT, 0);
                    glBindBuffer(GL_ARRAY_BUFFER, 0);
                    
                    glDisableClientState(GL_NORMAL_ARRAY);
                    glDisableClientState(GL_VERTEX_ARRAY);
                    
                glPopMatrix();
            }
        }
    glPopMatrix();
    
    glfwSwapBuffers(window);

}

} // namespace Geppetto 
