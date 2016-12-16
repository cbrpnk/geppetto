#ifndef _G_USER_INPUT_H_
#define _G_USER_INPUT_H_

#include <set>

#include "GLFW/glfw3.h"
#include "../ggame.h"
#include "gcomponent.h"


class GUserInputComponent: public GComponent {
public:
	GUserInputComponent(GEntity& e);
	~GUserInputComponent();
	
	static const int KEY_SPACE;
	static const int KEY_0;
	static const int KEY_1;
	static const int KEY_2;
	static const int KEY_3;
	static const int KEY_4;
	static const int KEY_5;
	static const int KEY_6;
	static const int KEY_7;
	static const int KEY_8;
	static const int KEY_9;
	static const int KEY_A;
	static const int KEY_B;
	static const int KEY_C;
	static const int KEY_D;
	static const int KEY_E;
	static const int KEY_F;
	static const int KEY_G;
	static const int KEY_H;
	static const int KEY_I;
	static const int KEY_J;
	static const int KEY_K;
	static const int KEY_L;
	static const int KEY_M;
	static const int KEY_N;
	static const int KEY_O;
	static const int KEY_P;
	static const int KEY_Q;
	static const int KEY_R;
	static const int KEY_S;
	static const int KEY_T;
	static const int KEY_U;
	static const int KEY_V;
	static const int KEY_W;
	static const int KEY_X;
	static const int KEY_Y;
	static const int KEY_Z;
	static const int KEY_ESCAPE;
	static const int KEY_ENTER;
	static const int KEY_TAB;
	static const int KEY_RIGHT;
	static const int KEY_LEFT;
	static const int KEY_DOWN;
	static const int KEY_UP;
	static const int KEY_LEFT_SHIFT;
	static const int KEY_LEFT_CONTROL;
	static const int KEY_LEFT_ALT;
	static const int KEY_RIGHT_SHIFT;
	static const int KEY_RIGHT_CONTROL;
	static const int KEY_RIGHT_ALT;
	
	
	int getMouseXMovement();
	int getMouseYMovement();
	bool keyPressed(const int key);

private:
	static std::set<unsigned int> keyboard;
	static int mouse_x;
	static int mouse_x_move;
	static int mouse_y;
	static int mouse_y_move;
	
	// GGame::init will register those callbacks through the GLFW API
	friend bool GGame::init();
	static void glfw_mouse_move_callback(GLFWwindow* window,
        double x_pos, double y_pos);
	static void glfw_mouse_button_callback(GLFWwindow* window,
        int button, int action, int mods);
	static void glfw_key_callback(GLFWwindow *window,
        int key, int scancode, int action, int mode);
};

#endif
