#include "GLFW/glfw3.h"
#include "guserinput.h"

const int GUserInputComponent::KEY_SPACE = GLFW_KEY_SPACE;
const int GUserInputComponent::KEY_0 = GLFW_KEY_0;
const int GUserInputComponent::KEY_1 = GLFW_KEY_1;
const int GUserInputComponent::KEY_2 = GLFW_KEY_2;
const int GUserInputComponent::KEY_3 = GLFW_KEY_3;
const int GUserInputComponent::KEY_4 = GLFW_KEY_4;
const int GUserInputComponent::KEY_5 = GLFW_KEY_5;
const int GUserInputComponent::KEY_6 = GLFW_KEY_6;
const int GUserInputComponent::KEY_7 = GLFW_KEY_7;
const int GUserInputComponent::KEY_8 = GLFW_KEY_8;
const int GUserInputComponent::KEY_9 = GLFW_KEY_9;
const int GUserInputComponent::KEY_A = GLFW_KEY_A;
const int GUserInputComponent::KEY_B = GLFW_KEY_B;
const int GUserInputComponent::KEY_C = GLFW_KEY_C;
const int GUserInputComponent::KEY_D = GLFW_KEY_D;
const int GUserInputComponent::KEY_E = GLFW_KEY_E;
const int GUserInputComponent::KEY_F = GLFW_KEY_F;
const int GUserInputComponent::KEY_G = GLFW_KEY_G;
const int GUserInputComponent::KEY_H = GLFW_KEY_H;
const int GUserInputComponent::KEY_I = GLFW_KEY_I;
const int GUserInputComponent::KEY_J = GLFW_KEY_J;
const int GUserInputComponent::KEY_K = GLFW_KEY_K;
const int GUserInputComponent::KEY_L = GLFW_KEY_L;
const int GUserInputComponent::KEY_M = GLFW_KEY_M;
const int GUserInputComponent::KEY_N = GLFW_KEY_N;
const int GUserInputComponent::KEY_O = GLFW_KEY_O;
const int GUserInputComponent::KEY_P = GLFW_KEY_P;
const int GUserInputComponent::KEY_Q = GLFW_KEY_Q;
const int GUserInputComponent::KEY_R = GLFW_KEY_R;
const int GUserInputComponent::KEY_S = GLFW_KEY_S;
const int GUserInputComponent::KEY_T = GLFW_KEY_T;
const int GUserInputComponent::KEY_U = GLFW_KEY_U;
const int GUserInputComponent::KEY_V = GLFW_KEY_V;
const int GUserInputComponent::KEY_W = GLFW_KEY_W;
const int GUserInputComponent::KEY_X = GLFW_KEY_X;
const int GUserInputComponent::KEY_Y = GLFW_KEY_Y;
const int GUserInputComponent::KEY_Z = GLFW_KEY_Z;
const int GUserInputComponent::KEY_ESCAPE = GLFW_KEY_ESCAPE;
const int GUserInputComponent::KEY_ENTER = GLFW_KEY_ENTER;
const int GUserInputComponent::KEY_TAB = GLFW_KEY_TAB;
const int GUserInputComponent::KEY_RIGHT = GLFW_KEY_RIGHT;
const int GUserInputComponent::KEY_LEFT = GLFW_KEY_LEFT;
const int GUserInputComponent::KEY_DOWN = GLFW_KEY_DOWN;
const int GUserInputComponent::KEY_UP = GLFW_KEY_UP;
const int GUserInputComponent::KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
const int GUserInputComponent::KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
const int GUserInputComponent::KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
const int GUserInputComponent::KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
const int GUserInputComponent::KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
const int GUserInputComponent::KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;

std::set<unsigned int> GUserInputComponent::keyboard;
int GUserInputComponent::mouse_x = 0;
int GUserInputComponent::mouse_x_move = 0;
int GUserInputComponent::mouse_y = 0;
int GUserInputComponent::mouse_y_move = 0;
int GUserInputComponent::xscroll = 0;
int GUserInputComponent::yscroll = 0;

GUserInputComponent::GUserInputComponent(GEntity& e) : GComponent(e)
{}

GUserInputComponent::~GUserInputComponent()
{}


int GUserInputComponent::getMouseXMovement()
{
	int move = mouse_x_move;
	mouse_x_move = 0;
	return move;
}


int GUserInputComponent::getMouseYMovement()
{
	int move = mouse_y_move;
	mouse_y_move = 0;
	return move;
}


bool GUserInputComponent::keyPressed(const int key)
{
	if(keyboard.find(key) != keyboard.end()) {
		return true;
	}
	return false;
}


void GUserInputComponent::glfw_mouse_button_callback(GLFWwindow* window,
    int button, int action, int mods)
{

}


void GUserInputComponent::glfw_mouse_move_callback(GLFWwindow* window,
    double x_pos, double y_pos)
{
	mouse_x_move = mouse_x - x_pos;
	mouse_y_move = mouse_y - y_pos;
	mouse_x = x_pos;
	mouse_y = y_pos;
}


void GUserInputComponent::glfw_mouse_scroll_callback(GLFWwindow* window,
    double xoffset, double yoffset)
{
	xscroll += xoffset;
	yscroll += yoffset;
}


void GUserInputComponent::glfw_key_callback(GLFWwindow* window,
    int key, int scancode, int action, int mode)
{
	if(action == GLFW_PRESS) {
		keyboard.insert(key);
	} else if(action == GLFW_RELEASE &&
		keyboard.find(key) != keyboard.end()) {
		keyboard.erase(key);
	}
}
