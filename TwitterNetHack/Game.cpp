#include "Game.h"

void Game::generateMaze() {
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		this->rooms[i] = new Room();
	}


}

Game::Game() {

}

Game::~Game() {
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		delete this->rooms[i];
	}
}
