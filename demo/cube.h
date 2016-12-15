#ifndef _CUBE_H_
#define _CUBE_H_

#include <string>

#include "../geppetto/geppetto.h"

class Cube : public Entity
{
public:
	float xRotationSpeed;
	float yRotationSpeed;
	float zRotationSpeed;
	
	Cube(std::string name);
	~Cube();
	
	void load();
	void update();
};

#endif
