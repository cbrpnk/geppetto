#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../geppetto/geppetto.h"

class Player : public Geppetto::Entity
{
public:
    float movement_acceleration;
    float rotation_speed;
    int zoomLevel;
    
    Player();
    ~Player();
    
    void Update();
};

#endif
