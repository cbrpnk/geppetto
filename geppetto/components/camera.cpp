#include "camera.h"
#include "../entity.h"

namespace Geppetto {
namespace Component {

Camera::Camera(Entity& e) : ComponentBase(e),
position(e.position),
up(e.up),
forward(e.forward)
{}


Camera::~Camera()
{}


Math::Vec3 Camera::GetForward()
{
    return forward;
}


Math::Vec3 Camera::GetPosition()
{
    return position;
}


Math::Vec3 Camera::GetUp()
{
    return up;
}


void Camera::SetForward(const Math::Vec3 f)
{
    forward = f;
}


void Camera::SetPosition(const Math::Vec3 p)
{
    position = p;
}


void Camera::SetUp(const Math::Vec3 u)
{
    up = u;
}

} // namespace Component
} // namespace Geppetto
