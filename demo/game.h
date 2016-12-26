#ifndef _DEMO_GAME_H_
#define _DEMO_GAME_H_

#include "../geppetto/geppetto.h"

class Game : public Geppetto::Game
{
public:
	Game();
	~Game();
	
	void Load();
	void Update();
};

#endif
