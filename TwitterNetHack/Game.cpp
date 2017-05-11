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
	this->player = new Player(this->textHandler, 100.0f, 60.0f, 20.0f);
	Enemy* enemy = new Enemy(this->textHandler, 70.0f, 45.0f, 15.0f, "Chestcunt", "It's a bitch boi");
	this->battleSequence(enemy);
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
		std::getline(std::cin, std::string());
		this->textHandler->printText(std::string("You hit ") + enemy->getName() + std::string("!"));
		enemy->damage(this->player->getAttack() - enemy->getDefense());
		if (enemy->getHealth() <= 0)
		{
			break;
		}
		this->textHandler->printText(enemy->getName() + std::string("'s remaining health: ") + std::to_string(int(enemy->getHealth())));
		std::getline(std::cin, std::string());
		this->textHandler->printText(std::string(std::string("") + enemy->getName() + std::string(" hits you!")));
		this->player->damage(enemy->getAttack() - this->player->getDefense());
		if (this->player->getHealth() <= 0)
		{
			break;
		}
		this->textHandler->printText(std::string("Your remaining health: ") + std::to_string(int(this->player->getHealth())));		
	}
}

void Game::PlayGame() {
	this->currentRoom = this->rooms[0];
	this->inputHandler->setObserver(this->rooms[0]);

	this->inputHandler->getInput();
}
