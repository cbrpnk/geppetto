#ifndef _GEPPETTO_USERINPUT_H_
#define _GEPPETTO_USERINPUT_H_

#include <set>

#include "GLFW/glfw3.h"
#include "../game.h"
#include "component_base.h"

namespace Geppetto {
namespace Component {

class UserInput: public ComponentBase {
public:
	
	
	struct Mouse {
		int xPos;
		int yPos;
		int xScroll;
		int yScroll;
		bool leftPress;
		bool rightPress;
	};
	
	
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
	
	static Mouse mouseState;
	static std::set<unsigned int> keyboardState;
	
	UserInput(Entity& e);
	~UserInput();
	
	bool KeyPressed(const int key);

private:
	
	// Game::Init will register those callbacks through the GLFW API
	friend bool Geppetto::Game::Init();
	static void GlfwMouseMoveCallback(GLFWwindow* window,
        double xPos, double yPos);
	static void GlfwMouseButtonCallback(GLFWwindow* window,
        int button, int action, int mods);
	static void GlfwMouseScrollCallback(GLFWwindow* window,
        double xScroll, double yScroll);
	static void GlfwKeyCallback(GLFWwindow *window,
        int key, int scancode, int action, int mode);
};

} // namespace Component
} // namespace Geppetto

#endif
