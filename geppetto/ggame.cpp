#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "gcomponents/gcamera.h"
#include "gcomponents/ggeometry.h"
#include "gcomponents/guserinput.h"
#include "ggame.h"
#include "gstage.h"


GGame* GGame::instance = nullptr;

GGame::GGame(std::string n, const int w, const int h) :
name(n),
width(w),
height(h)
{
	instance = this;
}

GGame::~GGame()
{
	for(auto gStage : gStages) {
		delete(gStage.second);
	}
}


void GGame::glfw_error_callback(int error, const char *desc)
{
	std::cout << "GLFW error: " << desc << std::endl;
}


GGame& GGame::getInstance()
{
	return *instance;
}


bool GGame::init()
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
	glfwSetKeyCallback(window, GUserInputComponent::glfw_key_callback);
	glfwSetCursorPosCallback(window, GUserInputComponent::glfw_mouse_move_callback);
	glfwSetMouseButtonCallback(window, GUserInputComponent::glfw_mouse_button_callback);
	
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


void GGame::run()
{
	while(runGGame) {
		glfwPollEvents();
		activeGStage->updateGStage();
		render();
	}
	
	glfwTerminate();
}


void GGame::shutdown()
{
	runGGame = false;
}


void GGame::addGStage(GStage* gStage)
{
	gStages.insert(std::make_pair(gStage->getName(), gStage));
}


GStage& GGame::getActiveGStage()
{
	return *activeGStage;
}


GStage* GGame::getGStage(std::string name)
{
	if(gStages.find(name) != gStages.end()) {
		return gStages[name];
	}
	return nullptr;
}


bool GGame::loadGStage(std::string name)
{
	GStage* gStage = getGStage(name);
	if(gStage) {
		activeGStage = gStage;
		gStage->loadGStage();
		return true;
	}
	return false;
}


/* Private */
void GGame::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glPushMatrix();
		
		GEntity* cameraGEntity = activeGStage->getCameraGEntity();
		
		GVec3 camera_position = cameraGEntity->position + cameraGEntity->getGCamera()->getPosition();
		GVec3 look_at = camera_position + cameraGEntity->forward;
		gluLookAt(camera_position.x, camera_position.y, camera_position.z, look_at.x, look_at.y, look_at.z, 0.0f, 1.0f, 0.0f);
		
		for(auto e : activeGStage->getGEntities()) {
			
			// Check if GEntity has a GGeometry component
			if(e.second->active && e.second->hasGComponent(GComponent::Type::GGeometry)) {
				
				glPushMatrix();
					glMultMatrixf(e.second->getReferenceFrame().toArray());
					
					// Select the right type of GGeometry
					GLenum type;
					switch(e.second->getGGeometry()->getType()) {
					case GGeometryComponent::Type::Points:
						type = GL_POINTS;
						break;
					case GGeometryComponent::Type::Lines:
						type = GL_LINES;
						break;
					case GGeometryComponent::Type::Triangles:
						type = GL_TRIANGLES;
						break;
					case GGeometryComponent::Type::Quads:
						type = GL_QUADS;
						break;
					default:
						type = GL_TRIANGLES;
						break;
					}
					
					glBegin(type);
						std::vector<float> vertices = e.second->getGGeometry()->getVertices();
						GVec3* vertex;
						for(size_t i=0; i<vertices.size(); i+=3) {
							glColor3f(1.0f, 0.1f, 0.1f);
							vertex = (GVec3*) &vertices[i];
							glVertex3f(vertex->x, vertex->y, vertex->z);
						}
					glEnd();
					
				glPopMatrix();
			}
		}
	glPopMatrix();
	
	glfwSwapBuffers(window);

}
