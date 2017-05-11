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
	this->player = new Player(this->textHandler, 100.0, 20.0, 20.0);
	this->inputHandler->setObserver(player);
}

Game::~Game() {
	for (int i = 0; i < NR_OF_ROOMS; i++) {
		delete this->rooms[i];
	}
	delete this->textHandler;
	delete this->inputHandler;
	delete this->player;
}

void Game::battleSequence(Enemy * enemy)
{
	this->textHandler->printText(std::string("You entered combat with: ") + enemy->getName());
	while (enemy->getHealth() > 0 && this->player->getHealth() > 0)
	{
		this->textHandler->printText(std::string("\nYou hit the enemy!\n"));
		enemy->damage(this->player->getAttack() - enemy->getDefense());
		this->textHandler->printText(enemy->getName() + std::string("'s remaining health: ") + std::to_string(enemy->getHealth()));
		this->textHandler->printText(std::string(std::string("\n") + enemy->getName() + std::string(" hits you!\n")));
		this->player->damage(enemy->getAttack() - this->player->getDefense);
		this->textHandler->printText(std::string("Your remaining health: ") + std::to_string(this->player->getHealth()) + std::string("\n"));
		system("pause");
	}
}

void Game::PlayGame() {
	this->currentRoom = this->rooms[0];
	this->inputHandler->setObserver(this->rooms[0]);

	this->inputHandler->getInput();
}
