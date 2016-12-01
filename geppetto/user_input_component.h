#ifndef _ENGINE_USER_INPUT_COMPONENT_H_
#define _ENGINE_USER_INPUT_COMPONENT_H_

#include <set>

#include "component.h"

class UserInputComponent: public Component {
public:
	UserInputComponent(Entity& e);
	~UserInputComponent();
	
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
	static void moveMouse(const int x, const int y);
	static void pressKey(const int key);
	static void releaseKey(const int key);

private:
	static std::set<int> keyboard;
	static int mouse_x;
	static int mouse_x_move;
	static int mouse_y;
	static int mouse_y_move;
};

#endif
