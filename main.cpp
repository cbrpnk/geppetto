#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "engine/geppetto.h"
#include "lib/gmath.h"


Scene demoScene;
static const int window_width = 800;
static const int window_height = 600;
bool endGame = false;


/*
 * Used by glfw to report errors
 */
void error_callback(int error, const char *desc) {
	std::cout << "GLFW error: " << desc << std::endl;
}


/*
 * Called by glfw when the user presses a key
 */
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	if(action == GLFW_PRESS) {
		UserInputComponent::pressKey(key);
	} else if(action == GLFW_RELEASE) {
		UserInputComponent::releaseKey(key);
	}
}


void cursor_pos_callback(GLFWwindow *window, double x_pos, double y_pos) {
	UserInputComponent::moveMouse(x_pos, y_pos);
}


void render(GLFWwindow* window, Entity& cam_entity) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glPushMatrix();
		// Apply camera transform
		
		// Check that entity has a camera
		Vec3 camera_position = cam_entity.position + cam_entity.components.getCamera()->getPosition();
		Vec3 look_at = camera_position + cam_entity.forward;
		gluLookAt(camera_position.x, camera_position.y, camera_position.z, look_at.x, look_at.y, look_at.z, 0.0f, 1.0f, 0.0f);
		
		for(auto e : demoScene.getEntities()) {
			
			// Check if entity has a geometry component
			if(e.second.components.isEnabled("Geometry")) {
				
				glPushMatrix();
					glMultMatrixf(e.second.getReferenceFrame().toArray());
					
					
					// Select the right type of geometry
					GLenum type;
					switch(e.second.components.getGeometry()->getType()) {
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
						
						for(auto vertex : e.second.components.getGeometry()->getVertices()) {
						}	
						
						glColor3f(0.9f, 0.1f, 0.1f);
						for(std::size_t j=0; j<24; ++j) {
							if(j%4 == 0) {
							}
							float x = e.second.components.getGeometry()->getVertices()[j*3+0];
							float y = e.second.components.getGeometry()->getVertices()[j*3+1];
							float z = e.second.components.getGeometry()->getVertices()[j*3+2];
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


void playerUpdate(Entity& player) {
	float movement_acceleration = 0.003f;
	float rotation_speed = 0.09f;
	std::shared_ptr<UserInputComponent> input = player.components.getUserInput();	
	std::shared_ptr<PhysicsComponent> physics = player.components.getPhysics();
	
	if(input->keyPressed(GLFW_KEY_W)) {
		physics->setAcceleration(physics->getAcceleration() + player.forward * movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_A)) {
		physics->setAcceleration(physics->getAcceleration() + Vec3(player.forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * -movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_S)) {
		physics->setAcceleration(physics->getAcceleration() + player.forward * -movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_D)) {
		physics->setAcceleration(physics->getAcceleration() += Vec3(player.forward).cross(Vec3(0.0f, 1.0f, 0.0f)) * movement_acceleration);
	}
	if(input->keyPressed(GLFW_KEY_ESCAPE)) {
		endGame = true;
	}
	
	player.rotate(-input->getMouseYMovement() * rotation_speed, input->getMouseXMovement() * rotation_speed, 0.0f);
}


int main(int argc, char **argv) {
	glfwSetErrorCallback(error_callback);
		
	if(!glfwInit())
	{
		std::cout << "failed to initialize glfw" << std::endl;
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLint w = window_width;
	GLint h = window_height;
	GLFWwindow *window = glfwCreateWindow(w, h, "Geppetto 0.1", nullptr, nullptr);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	if(glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize glew" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
	
	// Viewport and projection
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 1.0, 425.0);
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
	
	// Setup scene;	
	demoScene.setName("demoScene");
	
	Entity player;
	player.name = "Player";
	player.components.add("Logic");
	player.components.getLogic()->attach_update_function(playerUpdate);
	player.components.add("Physics");
	player.components.getPhysics()->setFrictionCoefficient(0.15f);
	player.components.add("Camera");
	player.components.getCamera()->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	player.components.add("UserInput");
	demoScene.addEntity(player);

	
	// Create cubes
	for(int i=0; i<256; ++i) {
		Entity entity;
		entity.name = "Cube" + std::to_string(i);
		entity.position.x = Gmath::randomFloat(-50.0f, 50.0f);
		entity.position.y = Gmath::randomFloat(1.0f, 4.0f);
		entity.position.z = Gmath::randomFloat(-50, 50);
		entity.rotate(Gmath::randomFloat(0, 360), 0, Gmath::randomFloat(0, 360));
		entity.components.add("Physics");
		entity.components.getPhysics()->setFrictionCoefficient(0.15f);
		entity.components.add("Geometry");
		entity.components.getGeometry()->loadVertices(GeometryComponent::Cube);
		entity.components.getGeometry()->setType(GeometryComponent::Type::Quads);
		demoScene.addEntity(entity);
	}
	
	
	// Game loop
	while(!endGame)
	{
		// User inputs
		glfwPollEvents();
		
		// Update State
		demoScene.update();
		
		// Render
		render(window, player);
	}
	
	glfwTerminate();
	return 0;
}
