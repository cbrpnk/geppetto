#ifndef _GEPPETTO_COMPONENT_H_
#define _GEPPETTO_COMPONENT_H_

#include <vector>

class GEntity;
class GGame;
class GStage;

class Component
{
public:
	enum class Type {
		Camera, Geometry, Physics, UserInput
	};
	
	GGame&   gGame;
	GStage&  gStage;
	GEntity& gEntity;
	
	Component(GEntity& e);
	virtual ~Component();
	virtual void update();
};

#endif
