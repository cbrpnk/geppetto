#ifndef _GCOMPONENT_H_
#define _GCOMPONENT_H_

#include <vector>

class GEntity;
class GGame;
class GStage;

class GComponent
{
public:
	enum class Type {
		GCamera, GGeometry, GPhysics, GUserInput
	};
	
	GGame&   gGame;
	GStage&  gStage;
	GEntity& gEntity;
	
	GComponent(GEntity& e);
	virtual ~GComponent();
	virtual void update();
};

#endif
