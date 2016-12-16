#ifndef _G_PHYSICS_H_
#define _G_PHYSICS_H_

#include "../gcomponent.h"
#include "../math/vec3.h"

class GPhysicsComponent : public GComponent {
public:
	
	GPhysicsComponent(GEntity& e);
	~GPhysicsComponent();
	
	Vec3  getAcceleration();
	float getFrictionCoefficient();
	Vec3  getVelocity();
	void  setAcceleration(const Vec3 a);
	void  setFrictionCoefficient(const float f);
	void  setVelocity(const Vec3 v);
	
	void update();

private:
	Vec3 acceleration;
	Vec3 velocity;
	float friction_coefficient;
};

#endif
