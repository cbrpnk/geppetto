#ifndef _GEPPETTO_CAMERA_COMPONENT_H_
#define _GEPPETTO_CAMERA_COMPONENT_H_

#include "component.h"

class CameraComponent : public Component {
public:
	
	CameraComponent(Entity& e);
	~CameraComponent();
	
	Vec3 getForward();
	Vec3 getPosition();
	Vec3 getUp();
	void setForward(Vec3 f);
	void setPosition(Vec3 p);
	void setUp(Vec3 u);
	
private:
	// position is relative to the position of the entity
	Vec3 position;
	Vec3 up;
	Vec3 forward;
};

#endif
