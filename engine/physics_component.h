#ifndef _ENGINE_PHYSICS_COMPONENT_H_
#define _ENGINE_PHYSICS_COMPONENT_H_

#include "component.h"
#include "../lib/vec3.h"

class PhysicsComponent : public Component {
public:
	
	PhysicsComponent(Entity& e);
	~PhysicsComponent();
	
	Vec3  getAcceleration();
	float getFrictionCoefficient();
	Vec3  getVelocity();
	void  setAcceleration(Vec3 a);
	void  setFrictionCoefficient(float f);
	void  setVelocity(Vec3 v);
	
	void update();

private:
	Vec3 acceleration;
	Vec3 velocity;
	float friction_coefficient;
};

#endif
