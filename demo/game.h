#ifndef _DEMO_GAME_H_
#define _DEMO_GAME_H_

#include "../geppetto/geppetto.h"

class Game : public GGame
{
public:
	Game();
	~Game();
	
	void load();
	void update();
};

#endif
