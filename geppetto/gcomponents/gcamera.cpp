#include "gcamera.h"
#include "../gentity.h"

GCameraComponent::GCameraComponent(GEntity& e) : GComponent(e),
position(e.position),
up(e.up),
forward(e.forward)
{}


GCameraComponent::~GCameraComponent()
{}


GVec3 GCameraComponent::getForward()
{
	return forward;
}


GVec3 GCameraComponent::getPosition()
{
	return position;
}


GVec3 GCameraComponent::getUp()
{
	return up;
}


void GCameraComponent::setForward(const GVec3 f)
{
	forward = f;
}


void GCameraComponent::setPosition(const GVec3 p)
{
	position = p;
}


void GCameraComponent::setUp(const GVec3 u)
{
	up = u;
}

