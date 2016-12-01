#ifndef _CUBE_H_
#define _CUBE_H_

#include "../geppetto/geppetto.h"

class Cube : public CustomClass
{
public:
	float xRotationSpeed;
	float yRotationSpeed;
	float zRotationSpeed;
	
	Cube();
	~Cube();
	
	void load(Entity* entity);
	void update(Entity* entity);
};

#endif
