#ifndef _GEPPETTO_PHYSICS_COMPONENT_H_
#define _GEPPETTO_PHYSICS_COMPONENT_H_

#include "../component.h"
#include "../math/vec3.h"

class PhysicsComponent : public Component {
public:
	
	PhysicsComponent(Entity& e);
	~PhysicsComponent();
	
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
