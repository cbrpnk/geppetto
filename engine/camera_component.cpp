#include "camera_component.h"

CameraComponent::CameraComponent(Entity& e) : Component(e) {
	position = e.position;
	up = e.up;
	forward = e.forward;
}


CameraComponent::~CameraComponent() {}


Vec3 CameraComponent::getForward() {
	return forward;
}


Vec3 CameraComponent::getPosition() {
	return position;
}


Vec3 CameraComponent::getUp() {
	return up;
}


void CameraComponent::setForward(Vec3 f) {
	forward = f;
}


void CameraComponent::setPosition(Vec3 p) {
	position = p;
}


void CameraComponent::setUp(Vec3 u) {
	up = u;
}

