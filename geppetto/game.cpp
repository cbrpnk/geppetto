#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "camera_component.h"
#include "game.h"
#include "geometry_component.h"
#include "stage.h"
#include "user_input_component.h"


Game::Game()
{}

Game::Game(const std::string title, const int w, const int h) : windowTitle(title),
width(w),
height(h)
{}

Game::~Game()
{}

/* Piblic */
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
	
	window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
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
	glfwSetKeyCallback(window, glfw_key_callback);
	glfwSetCursorPosCallback(window, glfw_cursor_callback);
	
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
		Stage::getActiveStage()->update();
		render();
	}
	
	glfwTerminate();
}


void Game::shutdown()
{
	runGame = false;
}


void Game::glfw_cursor_callback(GLFWwindow* window, double x_pos, double y_pos)
{
	UserInputComponent::moveMouse(x_pos, y_pos);
}


void Game::glfw_error_callback(int error, const char *desc)
{
	std::cout << "GLFW error: " << desc << std::endl;
}


void Game::glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(action == GLFW_PRESS) {
		UserInputComponent::pressKey(key);
	} else if(action == GLFW_RELEASE) {
		UserInputComponent::releaseKey(key);
	}
}


/* Private */
void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glPushMatrix();
		
		Stage* stage = Stage::getActiveStage();
		Entity* cameraEntity = stage->getCameraEntity();
		
		Vec3 camera_position = cameraEntity->position + cameraEntity->components.getCamera()->getPosition();
		Vec3 look_at = camera_position + cameraEntity->forward;
		gluLookAt(camera_position.x, camera_position.y, camera_position.z, look_at.x, look_at.y, look_at.z, 0.0f, 1.0f, 0.0f);
		
		for(auto e : stage->getEntities()) {
			
			// Check if entity has a geometry component
			if(e.second->components.isEnabled(Component::Type::Geometry)) {
				
				glPushMatrix();
					glMultMatrixf(e.second->getReferenceFrame().toArray());
					
					// Select the right type of geometry
					GLenum type;
					switch(e.second->components.getGeometry()->getType()) {
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
						
						for(auto vertex : e.second->components.getGeometry()->getVertices()) {
						}	
						
						glColor3f(0.9f, 0.1f, 0.1f);
						for(std::size_t j=0; j<24; ++j) {
							if(j%4 == 0) {
							}
							float x = e.second->components.getGeometry()->getVertices()[j*3+0];
							float y = e.second->components.getGeometry()->getVertices()[j*3+1];
							float z = e.second->components.getGeometry()->getVertices()[j*3+2];
							Vec4 point(x, y, z, 1);
							glVertex3f(point.x, point.y, point.z);
						}
					glEnd();
					
				glPopMatrix();
			}
		}
	glPopMatrix();
	
	glfwSwapBuffers(window);

}
