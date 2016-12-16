#ifndef _G_PHYSICS_H_
#define _G_PHYSICS_H_

#include "gcomponent.h"
#include "../gmath/gvec3.h"

class GPhysicsComponent : public GComponent {
public:
	
	GPhysicsComponent(GEntity& e);
	~GPhysicsComponent();
	
	GVec3  getAcceleration();
	float getFrictionCoefficient();
	GVec3  getVelocity();
	void  setAcceleration(const GVec3 a);
	void  setFrictionCoefficient(const float f);
	void  setVelocity(const GVec3 v);
	
	void update();

private:
	GVec3 acceleration;
	GVec3 velocity;
	float friction_coefficient;
};

#endif
