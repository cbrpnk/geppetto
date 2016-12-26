#ifndef _G_CAMERA_H_
#define _G_CAMERA_H_

#include "../math/vec3.h"
#include "component_base.h"

namespace Geppetto {
namespace Component {

class Camera : public ComponentBase
{
public:
	
	Camera(Entity& e);
	~Camera();
	
	Math::Vec3 GetForward();
	Math::Vec3 GetPosition();
	Math::Vec3 GetUp();
	void       SetForward(const Math::Vec3 f);
	void       SetPosition(const Math::Vec3 p);
	void       SetUp(const Math::Vec3 u);
	
private:
	// position is relative to the position of the Entity
	Math::Vec3 position;
	Math::Vec3 up;
	Math::Vec3 forward;
};

} // namespace Component
} // namespace Geppetto

#endif
