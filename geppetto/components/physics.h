#ifndef _GEPPETTO_PHYSICS_H_
#define _GEPPETTO_PHYSICS_H_

#include "component_base.h"
#include "../math/vec3.h"


namespace Geppetto {
namespace Component {

class Physics : public ComponentBase
{
public:
    
    Physics(Entity& e);
    ~Physics();
    
    Math::Vec3 GetAcceleration();
    float      GetFrictionCoefficient();
    Math::Vec3 GetVelocity();
    void       SetAcceleration(const Math::Vec3 a);
    void       SetFrictionCoefficient(const float f);
    void       SetVelocity(const Math::Vec3 v);
    
    void Update();

private:
    Math::Vec3 acceleration;
    Math::Vec3 velocity;
    float frictionCoefficient;
};

} // namespace Component
} // namespace Geppetto

#endif
