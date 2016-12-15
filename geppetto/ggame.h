#ifndef _GGAME_H_
#define _GGAME_H_

#include <GLFW/glfw3.h>
#include <string>
#include <map>

class GStage;

class GGame
{
public:
	static void  glfw_error_callback(int error, const char *desc);
	static GGame& getInstance();
	
	GGame(const std::string t, const int w, const int h);
	~GGame();
	
	bool init();
	void run();
	void shutdown();
	
	/* GStage */
	void   addGStage(GStage* GStage);
	GStage& getActiveGStage();
	GStage* getGStage(std::string name);
	bool   loadGStage(std::string name);
	
protected:
	static GGame* instance;
	std::string name;
	GLFWwindow* window;
	int width;
	int height;
	bool runGGame = true;
	
	/* GStages */
	GStage* activeGStage;
	std::map<std::string, GStage*> gStages;
	
private:	
	void render();
};


#endif
