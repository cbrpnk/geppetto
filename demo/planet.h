#ifndef _PLANET_H_
#define _PLANET_H_

#include <string>

#include "../geppetto/geppetto.h"

class Planet : public Geppetto::Entity
{
public:
    float rotationSpeed;
    
    Planet(std::string name);
    ~Planet();
    
    void Update();
};

#endif
