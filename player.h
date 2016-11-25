#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "engine/geppetto.h"

class Player : public CustomClass {
public:
	Player();
	~Player();
	
	void load();
	void update(Entity* entity);
};

#endif
