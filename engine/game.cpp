#include "game.h"

Game::Game() {};

Game::~Game() {};

void Game::shutdown() {
	isShuttingDown = 1;
}
