#ifndef _GEPPETTO_GAME_H_
#define _GEPPETTO_GAME_H_

#include <GLFW/glfw3.h>
#include <string>
#include <map>

class Stage;


class Game
{
public:
	static void glfw_error_callback(int error, const char *desc);
	
	Game(const std::string t, const int w, const int h);
	~Game();
	
	bool init();
	void run();
	void shutdown();
	
	/* Stage */
	void   addStage(Stage* stage);
	Stage* getActiveStage();
	Stage* getStage(std::string name);
	void   loadStage(std::string name);
	
private:
	std::string name;
	GLFWwindow* window;
	int width;
	int height;
	bool runGame = true;
	
	/* Stages */
	Stage* activeStage;
	std::map<std::string, Stage*> stages;
	
	void render();
};


#endif
