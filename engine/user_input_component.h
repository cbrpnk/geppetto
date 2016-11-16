#ifndef _ENGINE_USER_INPUT_COMPONENT_H_
#define _ENGINE_USER_INPUT_COMPONENT_H_

#include <set>

#include "component.h"

class UserInputComponent: public Component {
public:
	UserInputComponent(Entity& e);
	~UserInputComponent();
	
	int getMouseXMovement();
	int getMouseYMovement();
	bool keyPressed(int key);
	static void moveMouse(int x, int y);
	static void pressKey(int key);
	static void releaseKey(int key);

private:
	static std::set<int> keyboard;
	static int mouse_x;
	static int mouse_x_move;
	static int mouse_y;
	static int mouse_y_move;
};

#endif
