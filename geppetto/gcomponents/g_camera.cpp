#include "g_camera.h"
#include "../gentity.h"

GCameraComponent::GCameraComponent(GEntity& e) : GComponent(e),
position(e.position),
up(e.up),
forward(e.forward)
{}


GCameraComponent::~GCameraComponent()
{}


Vec3 GCameraComponent::getForward()
{
	return forward;
}


Vec3 GCameraComponent::getPosition()
{
	return position;
}


Vec3 GCameraComponent::getUp()
{
	return up;
}


void GCameraComponent::setForward(const Vec3 f)
{
	forward = f;
}


void GCameraComponent::setPosition(const Vec3 p)
{
	position = p;
}


void GCameraComponent::setUp(const Vec3 u)
{
	up = u;
}

