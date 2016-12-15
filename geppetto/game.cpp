#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "components/camera_component.h"
#include "components/geometry_component.h"
#include "components/user_input_component.h"
#include "game.h"
#include "stage.h"


Game* Game::instance = nullptr;

Game::Game(std::string n, const int w, const int h) :
name(n),
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


void Game::glfw_error_callback(int error, const char *desc)
{
	std::cout << "GLFW error: " << desc << std::endl;
}


Game& Game::getInstance()
{
	return *instance;
}


bool Game::init()
{
	glfwSetErrorCallback(glfw_error_callback);
		
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
	glfwSetKeyCallback(window, UserInputComponent::glfw_key_callback);
	glfwSetCursorPosCallback(window, UserInputComponent::glfw_mouse_move_callback);
	glfwSetMouseButtonCallback(window, UserInputComponent::glfw_mouse_button_callback);
	
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


void Game::run()
{
	while(runGame) {
		glfwPollEvents();
		activeStage->updateStage();
		render();
	}
	
	glfwTerminate();
}


void Game::shutdown()
{
	runGame = false;
}


void Game::addStage(Stage* stage)
{
	stages.insert(std::make_pair(stage->getName(), stage));
}


Stage& Game::getActiveStage()
{
	return *activeStage;
}


Stage* Game::getStage(std::string name)
{
	if(stages.find(name) != stages.end()) {
		return stages[name];
	}
	return nullptr;
}


bool Game::loadStage(std::string name)
{
	Stage* stage = getStage(name);
	if(stage) {
		activeStage = stage;
		stage->loadStage();
		return true;
	}
	return false;
}


/* Private */
void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glPushMatrix();
		
		Entity* cameraEntity = activeStage->getCameraEntity();
		
		Vec3 camera_position = cameraEntity->position + cameraEntity->getCamera()->getPosition();
		Vec3 look_at = camera_position + cameraEntity->forward;
		gluLookAt(camera_position.x, camera_position.y, camera_position.z, look_at.x, look_at.y, look_at.z, 0.0f, 1.0f, 0.0f);
		
		for(auto e : activeStage->getEntities()) {
			
			// Check if entity has a geometry component
			if(e.second->active && e.second->hasComponent(Component::Type::Geometry)) {
				
				glPushMatrix();
					glMultMatrixf(e.second->getReferenceFrame().toArray());
					
					// Select the right type of geometry
					GLenum type;
					switch(e.second->getGeometry()->getType()) {
					case GeometryComponent::Type::Points:
						type = GL_POINTS;
						break;
					case GeometryComponent::Type::Lines:
						type = GL_LINES;
						break;
					case GeometryComponent::Type::Triangles:
						type = GL_TRIANGLES;
						break;
					case GeometryComponent::Type::Quads:
						type = GL_QUADS;
						break;
					default:
						type = GL_TRIANGLES;
						break;
					}
					
					glBegin(type);
						std::vector<float> vertices = e.second->getGeometry()->getVertices();
						Vec3* vertex;
						for(size_t i=0; i<vertices.size(); i+=3) {
							glColor3f(1.0f, 0.1f, 0.1f);
							vertex = (Vec3*) &vertices[i];
							glVertex3f(vertex->x, vertex->y, vertex->z);
						}
					glEnd();
					
				glPopMatrix();
			}
		}
	glPopMatrix();
	
	glfwSwapBuffers(window);

}
