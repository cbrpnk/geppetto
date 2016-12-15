#ifndef _GEPPETTO_CAMERA_COMPONENT_H_
#define _GEPPETTO_CAMERA_COMPONENT_H_

#include "../math/vec3.h"
#include "../component.h"

class CameraComponent : public Component
{
public:
	
	CameraComponent(GEntity& e);
	~CameraComponent();
	
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
