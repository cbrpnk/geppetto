#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../geppetto/geppetto.h"

class Player : public CustomClass {
public:
	Player();
	~Player();
	
	void load();
	void update(Entity* entity);
};

#endif
