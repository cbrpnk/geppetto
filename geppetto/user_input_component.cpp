#include "user_input_component.h"


std::set<int> UserInputComponent::keyboard;
int UserInputComponent::mouse_x = 0;
int UserInputComponent::mouse_x_move = 0;
int UserInputComponent::mouse_y = 0;
int UserInputComponent::mouse_y_move = 0;

UserInputComponent::UserInputComponent(Entity& e) : Component(e) {}
UserInputComponent::~UserInputComponent() {}


int UserInputComponent::getMouseXMovement() {
	int move = mouse_x_move;
	mouse_x_move = 0;
	return move;
}


int UserInputComponent::getMouseYMovement() {
	int move = mouse_y_move;
	mouse_y_move = 0;
	return move;
}


bool UserInputComponent::keyPressed(int key) {
	if(keyboard.find(key) != keyboard.end()) {
		return true;
	}
	return false;
}


void UserInputComponent::moveMouse(int x, int y) {
	mouse_x_move = mouse_x - x;
	mouse_y_move = mouse_y - y;
	mouse_x = x;
	mouse_y = y;
}


void UserInputComponent::pressKey(int key) {
	keyboard.insert(key);
}


void UserInputComponent::releaseKey(int key) {
	if(keyboard.find(key) != keyboard.end()) {
		keyboard.erase(key);
	}
}
