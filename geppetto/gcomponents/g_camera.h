#ifndef _G_CAMERA_H_
#define _G_CAMERA_H_

#include "../math/vec3.h"
#include "../gcomponent.h"

class GCameraComponent : public GComponent
{
public:
	
	GCameraComponent(GEntity& e);
	~GCameraComponent();
	
	Vec3 getForward();
	Vec3 getPosition();
	Vec3 getUp();
	void setForward(const Vec3 f);
	void setPosition(const Vec3 p);
	void setUp(const Vec3 u);
	
private:
	// position is relative to the position of the GEntity
	Vec3 position;
	Vec3 up;
	Vec3 forward;
};

#endif
