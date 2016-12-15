#ifndef _DEMO_GAME_H_
#define _DEMO_GAME_H_

#include "../geppetto/geppetto.h"

class DemoGame : public Game
{
public:
	DemoGame();
	~DemoGame();
	
	void load();
	void update();
};

#endif
