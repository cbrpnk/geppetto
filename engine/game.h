#ifndef _ENGINE_GAME_H_
#define _ENGINE_GAME_H


class Game {
public:
	int isShuttingDown=0;
	
	Game();
	~Game();
	
	void shutdown();
};


#endif
