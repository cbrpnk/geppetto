#ifndef _DEMO_SCENE_H_
#define _DEMO_SCENE_H_

#include "../geppetto/scene.h"

class DemoScene : public Scene {
public:
	
	DemoScene(Game& parentGame);
	~DemoScene();
	
	void load();
};

#endif
