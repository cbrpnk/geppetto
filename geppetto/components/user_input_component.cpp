#include "GLFW/glfw3.h"
#include "user_input_component.h"

const int UserInputComponent::KEY_SPACE = GLFW_KEY_SPACE;
const int UserInputComponent::KEY_0 = GLFW_KEY_0;
const int UserInputComponent::KEY_1 = GLFW_KEY_1;
const int UserInputComponent::KEY_2 = GLFW_KEY_2;
const int UserInputComponent::KEY_3 = GLFW_KEY_3;
const int UserInputComponent::KEY_4 = GLFW_KEY_4;
const int UserInputComponent::KEY_5 = GLFW_KEY_5;
const int UserInputComponent::KEY_6 = GLFW_KEY_6;
const int UserInputComponent::KEY_7 = GLFW_KEY_7;
const int UserInputComponent::KEY_8 = GLFW_KEY_8;
const int UserInputComponent::KEY_9 = GLFW_KEY_9;
const int UserInputComponent::KEY_A = GLFW_KEY_A;
const int UserInputComponent::KEY_B = GLFW_KEY_B;
const int UserInputComponent::KEY_C = GLFW_KEY_C;
const int UserInputComponent::KEY_D = GLFW_KEY_D;
const int UserInputComponent::KEY_E = GLFW_KEY_E;
const int UserInputComponent::KEY_F = GLFW_KEY_F;
const int UserInputComponent::KEY_G = GLFW_KEY_G;
const int UserInputComponent::KEY_H = GLFW_KEY_H;
const int UserInputComponent::KEY_I = GLFW_KEY_I;
const int UserInputComponent::KEY_J = GLFW_KEY_J;
const int UserInputComponent::KEY_K = GLFW_KEY_K;
const int UserInputComponent::KEY_L = GLFW_KEY_L;
const int UserInputComponent::KEY_M = GLFW_KEY_M;
const int UserInputComponent::KEY_N = GLFW_KEY_N;
const int UserInputComponent::KEY_O = GLFW_KEY_O;
const int UserInputComponent::KEY_P = GLFW_KEY_P;
const int UserInputComponent::KEY_Q = GLFW_KEY_Q;
const int UserInputComponent::KEY_R = GLFW_KEY_R;
const int UserInputComponent::KEY_S = GLFW_KEY_S;
const int UserInputComponent::KEY_T = GLFW_KEY_T;
const int UserInputComponent::KEY_U = GLFW_KEY_U;
const int UserInputComponent::KEY_V = GLFW_KEY_V;
const int UserInputComponent::KEY_W = GLFW_KEY_W;
const int UserInputComponent::KEY_X = GLFW_KEY_X;
const int UserInputComponent::KEY_Y = GLFW_KEY_Y;
const int UserInputComponent::KEY_Z = GLFW_KEY_Z;
const int UserInputComponent::KEY_ESCAPE = GLFW_KEY_ESCAPE;
const int UserInputComponent::KEY_ENTER = GLFW_KEY_ENTER;
const int UserInputComponent::KEY_TAB = GLFW_KEY_TAB;
const int UserInputComponent::KEY_RIGHT = GLFW_KEY_RIGHT;
const int UserInputComponent::KEY_LEFT = GLFW_KEY_LEFT;
const int UserInputComponent::KEY_DOWN = GLFW_KEY_DOWN;
const int UserInputComponent::KEY_UP = GLFW_KEY_UP;
const int UserInputComponent::KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
const int UserInputComponent::KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
const int UserInputComponent::KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
const int UserInputComponent::KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
const int UserInputComponent::KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
const int UserInputComponent::KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;

std::set<unsigned int> UserInputComponent::keyboard;
int UserInputComponent::mouse_x = 0;
int UserInputComponent::mouse_x_move = 0;
int UserInputComponent::mouse_y = 0;
int UserInputComponent::mouse_y_move = 0;

UserInputComponent::UserInputComponent(Entity& e) : Component(e)
{}

UserInputComponent::~UserInputComponent()
{}


int UserInputComponent::getMouseXMovement()
{
	int move = mouse_x_move;
	mouse_x_move = 0;
	return move;
}


int UserInputComponent::getMouseYMovement()
{
	int move = mouse_y_move;
	mouse_y_move = 0;
	return move;
}


bool UserInputComponent::keyPressed(const int key)
{
	if(keyboard.find(key) != keyboard.end()) {
		return true;
	}
	return false;
}


void UserInputComponent::glfw_mouse_button_callback(GLFWwindow* window,
    int button, int action, int mods)
{

}


void UserInputComponent::glfw_mouse_move_callback(GLFWwindow* window,
    double x_pos, double y_pos)
{
	mouse_x_move = mouse_x - x_pos;
	mouse_y_move = mouse_y - y_pos;
	mouse_x = x_pos;
	mouse_y = y_pos;
}


void UserInputComponent::glfw_key_callback(GLFWwindow* window,
    int key, int scancode, int action, int mode)
{
	if(action == GLFW_PRESS) {
		keyboard.insert(key);
	} else if(action == GLFW_RELEASE &&
		keyboard.find(key) != keyboard.end()) {
		keyboard.erase(key);
	}
}
