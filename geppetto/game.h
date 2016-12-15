#ifndef _GEPPETTO_GAME_H_
#define _GEPPETTO_GAME_H_

#include <GLFW/glfw3.h>
#include <string>
#include <map>

class Stage;


class Game
{
public:
	static void  glfw_error_callback(int error, const char *desc);
	static Game& getInstance();
	
	Game(const std::string t, const int w, const int h);
	~Game();
	
	bool init();
	void run();
	void shutdown();
	
	/* Stage */
	void   addStage(Stage* stage);
	Stage& getActiveStage();
	Stage* getStage(std::string name);
	bool   loadStage(std::string name);
	
protected:
	static Game* instance;
	std::string name;
	GLFWwindow* window;
	int width;
	int height;
	bool runGame = true;
	
	/* Stages */
	Stage* activeStage;
	std::map<std::string, Stage*> stages;
	
private:	
	void render();
};


#endif
