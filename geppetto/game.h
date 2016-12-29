#ifndef _GEPPETTO_GAME_H_
#define _GEPPETTO_GAME_H_

#include <GLFW/glfw3.h>
#include <string>
#include <map>

namespace Geppetto {

class Stage;

class Game
{
public:
	static void  GlfwErrorCallback(int error, const char *desc);
	static Game& GetInstance();
	
	Game(const std::string t, const int w, const int h);
	~Game();
	
	bool Init();
	void Run();
	void Shutdown();
	
	/* Stage */
	void   SetActiveStage(Stage* stage);
	Stage* GetActiveStage();
	
protected:
	static Game* instance;
	std::string name;
	GLFWwindow* window;
	int width;
	int height;
	bool runGame = true;
	Stage* activeStage;
	
private:	
	void Render();
};

} // namespace Geppetto


#endif
