#ifndef _G_CAMERA_H_
#define _G_CAMERA_H_

#include "../gmath/gvec3.h"
#include "gcomponent.h"

class GCameraComponent : public GComponent
{
public:
	
	GCameraComponent(GEntity& e);
	~GCameraComponent();
	
	GVec3 getForward();
	GVec3 getPosition();
	GVec3 getUp();
	void setForward(const GVec3 f);
	void setPosition(const GVec3 p);
	void setUp(const GVec3 u);
	
private:
	// position is relative to the position of the GEntity
	GVec3 position;
	GVec3 up;
	GVec3 forward;
};

#endif
