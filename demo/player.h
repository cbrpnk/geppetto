#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../geppetto/geppetto.h"

class Player : public CustomClass
{
public:
	float movement_acceleration;
	float rotation_speed;
	
	Player();
	~Player();
	
	void load(Entity* entity);
	void update(Entity* entity);
};

#endif
