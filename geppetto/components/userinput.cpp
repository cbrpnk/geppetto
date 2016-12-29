#include "GLFW/glfw3.h"
#include "userinput.h"

namespace Geppetto {
namespace Component {

// public static
const int UserInput::KEY_SPACE         = GLFW_KEY_SPACE;
const int UserInput::KEY_0             = GLFW_KEY_0;
const int UserInput::KEY_1             = GLFW_KEY_1;
const int UserInput::KEY_2             = GLFW_KEY_2;
const int UserInput::KEY_3             = GLFW_KEY_3;
const int UserInput::KEY_4             = GLFW_KEY_4;
const int UserInput::KEY_5             = GLFW_KEY_5;
const int UserInput::KEY_6             = GLFW_KEY_6;
const int UserInput::KEY_7             = GLFW_KEY_7;
const int UserInput::KEY_8             = GLFW_KEY_8;
const int UserInput::KEY_9             = GLFW_KEY_9;
const int UserInput::KEY_A             = GLFW_KEY_A;
const int UserInput::KEY_B             = GLFW_KEY_B;
const int UserInput::KEY_C             = GLFW_KEY_C;
const int UserInput::KEY_D             = GLFW_KEY_D;
const int UserInput::KEY_E             = GLFW_KEY_E;
const int UserInput::KEY_F             = GLFW_KEY_F;
const int UserInput::KEY_G             = GLFW_KEY_G;
const int UserInput::KEY_H             = GLFW_KEY_H;
const int UserInput::KEY_I             = GLFW_KEY_I;
const int UserInput::KEY_J             = GLFW_KEY_J;
const int UserInput::KEY_K             = GLFW_KEY_K;
const int UserInput::KEY_L             = GLFW_KEY_L;
const int UserInput::KEY_M             = GLFW_KEY_M;
const int UserInput::KEY_N             = GLFW_KEY_N;
const int UserInput::KEY_O             = GLFW_KEY_O;
const int UserInput::KEY_P             = GLFW_KEY_P;
const int UserInput::KEY_Q             = GLFW_KEY_Q;
const int UserInput::KEY_R             = GLFW_KEY_R;
const int UserInput::KEY_S             = GLFW_KEY_S;
const int UserInput::KEY_T             = GLFW_KEY_T;
const int UserInput::KEY_U             = GLFW_KEY_U;
const int UserInput::KEY_V             = GLFW_KEY_V;
const int UserInput::KEY_W             = GLFW_KEY_W;
const int UserInput::KEY_X             = GLFW_KEY_X;
const int UserInput::KEY_Y             = GLFW_KEY_Y;
const int UserInput::KEY_Z             = GLFW_KEY_Z;
const int UserInput::KEY_ESCAPE        = GLFW_KEY_ESCAPE;
const int UserInput::KEY_ENTER         = GLFW_KEY_ENTER;
const int UserInput::KEY_TAB           = GLFW_KEY_TAB;
const int UserInput::KEY_RIGHT         = GLFW_KEY_RIGHT;
const int UserInput::KEY_LEFT          = GLFW_KEY_LEFT;
const int UserInput::KEY_DOWN          = GLFW_KEY_DOWN;
const int UserInput::KEY_UP            = GLFW_KEY_UP;
const int UserInput::KEY_LEFT_SHIFT    = GLFW_KEY_LEFT_SHIFT;
const int UserInput::KEY_LEFT_CONTROL  = GLFW_KEY_LEFT_CONTROL;
const int UserInput::KEY_LEFT_ALT      = GLFW_KEY_LEFT_ALT;
const int UserInput::KEY_RIGHT_SHIFT   = GLFW_KEY_RIGHT_SHIFT;
const int UserInput::KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
const int UserInput::KEY_RIGHT_ALT     = GLFW_KEY_RIGHT_ALT;

// Static
UserInput::Mouse UserInput::mouseState = {0, 0, 0, 0};
std::set<unsigned int> UserInput::keyboardState;


UserInput::UserInput(Entity& e) : ComponentBase(e)
{}


UserInput::~UserInput()
{}


bool UserInput::KeyPressed(const int key)
{
    if(keyboardState.find(key) != keyboardState.end()) {
        return true;
    }
    return false;
}


void UserInput::GlfwMouseButtonCallback(GLFWwindow* window,
    int button, int action, int mods)
{
    // TODO
}


void UserInput::GlfwMouseMoveCallback(GLFWwindow* window,
    double xPos, double yPos)
{
    mouseState.xPos = xPos;
    mouseState.yPos = yPos;
}


void UserInput::GlfwMouseScrollCallback(GLFWwindow* window,
    double xScroll, double yScroll)
{
    mouseState.xScroll += xScroll;
    mouseState.yScroll += yScroll;
}


void UserInput::GlfwKeyCallback(GLFWwindow* window,
    int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS) {
        keyboardState.insert(key);
    } else if(action == GLFW_RELEASE &&
        keyboardState.find(key) != keyboardState.end()) {
        keyboardState.erase(key);
    }
}


} // namespace Component
} // namespace Geppetto
