#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../geppetto/geppetto.h"

class Player : public GEntity
{
public:
	float movement_acceleration;
	float rotation_speed;
	
	Player();
	~Player();
	
	void load();
	void update();
};

#endif
