#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "components/camera.h"
#include "components/geometry.h"
#include "components/userinput.h"
#include "game.h"
#include "stage.h"

namespace Geppetto {

Game* Game::instance = nullptr;

Game::Game(std::string n, const int w, const int h) :
name(n),
window(nullptr),
width(w),
height(h)
{
	instance = this;
}

Game::~Game()
{
	for(auto stage : stages) {
		delete(stage.second);
	}
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
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_FOG);
	glFogf(GL_FOG_START, 40.0f);
	glFogf(GL_FOG_END, 90.0f);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	
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


void Game::AddStage(Stage* stage)
{
	stages.insert(std::make_pair(stage->GetName(), stage));
}


Stage& Game::GetActiveStage()
{
	return *activeStage;
}


Stage* Game::GetStage(std::string name)
{
	if(stages.find(name) != stages.end()) {
		return stages[name];
	}
	return nullptr;
}


bool Game::LoadStage(std::string name)
{
	Stage* stage = GetStage(name);
	if(stage) {
		activeStage = stage;
		stage->LoadStage();
		return true;
	}
	return false;
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
		
		for(auto e : activeStage->GetGEntities()) {
			
			// Check if Entity has a Geometry component
			if(e.second->active && e.second->HasComponent(Component::Type::Geometry)) {
				
				glPushMatrix();
					glMultMatrixf(e.second->GetReferenceFrame().ToArray());
					
					// Select the right type of Geometry
					GLenum type;
					switch(e.second->GetGeometry()->GetType()) {
					case Component::Geometry::Type::Points:
						type = GL_POINTS;
						break;
					case Component::Geometry::Type::Lines:
						type = GL_LINES;
						break;
					case Component::Geometry::Type::Triangles:
						type = GL_TRIANGLES;
						break;
					case Component::Geometry::Type::Quads:
						type = GL_QUADS;
						break;
					default:
						type = GL_TRIANGLES;
						break;
					}
					
					glBegin(type);
						std::vector<float> vertices = e.second->GetGeometry()->GetVertices();
						Math::Vec3* vertex;
						for(size_t i=0; i<vertices.size(); i+=3) {
							glColor3f(1.0f, 0.1f, 0.1f);
							vertex = (Math::Vec3*) &vertices[i];
							glVertex3f(vertex->x, vertex->y, vertex->z);
						}
					glEnd();
					
				glPopMatrix();
			}
		}
	glPopMatrix();
	
	glfwSwapBuffers(window);

}

} // namespace Geppetto 
