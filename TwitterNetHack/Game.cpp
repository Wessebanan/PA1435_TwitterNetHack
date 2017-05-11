#include "Game.h"

void Game::generateMaze() {
	// Automatic maze generation to be added later in development cycle
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		this->rooms[i] = new Room(this->textHandler, i);
	}
	this->rooms[0]->setNeighbour(this->rooms[1], 0);

	this->rooms[1]->setNeighbour(this->rooms[0], 2);
	this->rooms[1]->setNeighbour(this->rooms[2], 3);
	this->rooms[1]->setNeighbour(this->rooms[3], 1);

	this->rooms[2]->setNeighbour(this->rooms[1], 1);

	this->rooms[3]->setNeighbour(this->rooms[1], 3);
	this->rooms[3]->setNeighbour(this->rooms[4], 0);

	this->rooms[4]->setNeighbour(this->rooms[3], 2);
}

Game::Game() {
	this->textHandler = new TextHandler();
	this->inputHandler = new InputHandler(this->textHandler);
	this->player = new Player();

}

Game::~Game() {
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		delete this->rooms[i];
	}
	delete this->textHandler;
	delete this->inputHandler;
	delete this->player;
}
