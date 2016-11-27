#ifndef _GEPPETTO_GAME_H_
#define _GEPPETTO_GAME_H

#include <GLFW/glfw3.h>
#include <string>


class Game {
public:
	
	Game();
	Game(std::string title, int w, int h);
	~Game();
	
	static void glfw_cursor_callback(GLFWwindow *window, double x_pos, double y_pos);
	static void glfw_error_callback(int error, const char *desc);
	static void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
	
	bool init();
	void shutdown();
	void render();
	void run();

private:
	GLFWwindow* window;
	std::string windowTitle;
	int width;
	int height;
	bool runGame = true;
};


#endif
