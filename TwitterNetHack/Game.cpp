#include "Game.h"

void Game::generateMaze() {
	// Automatic maze generation to be added later in development cycle
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		this->rooms[i] = new Room();
	}


}

Game::Game() {
	this->textHandler = new TextHandler();
	this->inputHandler = new InputHandler(this->textHandler);
	this->player = new Player(eky5);

}

Game::~Game() {
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		delete this->rooms[i];
	}
	delete this->textHandler;
	delete this->inputHandler;
	delete this->player;
}
