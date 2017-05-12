#include "Game.h"

void Game::processInput(std::string input)
{
	if (input == "Move" || input == "move") {
		std::string target;
		this->textHandler->printText(std::string("Where do you want to move?"));
		target = this->inputHandler->getInput();
		if (target == "north" || target == "east" || target == "south" || target == "west") {
			this->currentRoom = this->currentRoom->moveToRoom(target);
		}
		else {
			Enemy* tempEnemy = this->currentRoom->moveToEnemy(target);
			if (tempEnemy != nullptr) {
				this->battleSequence(tempEnemy);
			}
			else {
				Obstacle* tempObstacle = this->currentRoom->moveToObstacle(target);
				if (tempObstacle != nullptr) {
					this->currentRoom->traverseObstacle(target, this->player);
				}
				else {
					this->textHandler->printText(std::string("That target does not exist in this room."));
				}
			}
		}
	}

	else if (input == "Look" || input == "look") {
		std::string target;  
		this->textHandler->printText(std::string("Look around or at somthing? (around/at)"));
		target = this->inputHandler->getInput();
		if (target == "around" ) {
			 this->currentRoom->lookAround();
		}
		else if (target == "at") {
			this->textHandler->printText(std::string("What do you want to look at?"));
			target = this->inputHandler->getInput();
			this->currentRoom->lookat(target);
		}
	}
}
 
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
	this->generateMaze();
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
	std::string response = "";
	while (true)
	{
		this->textHandler->printText(std::string("\nWhat do you want to do? (a: attack, f: flee)"));
		std::getline(std::cin, response);
		if (response == "a")
		{
			this->textHandler->printText(std::string("\nYou hit ") + enemy->getName() + std::string("!"));
			enemy->damage(this->player->getAttack() - enemy->getDefense());
			if (enemy->getHealth() <= 0)
			{
				this->currentRoom->removeEnemy(enemy->getName());
				break;
			}
			 
			this->textHandler->printText(std::string(std::string("") + enemy->getName() + std::string(" hits you!")));
			this->player->damage(enemy->getAttack() - this->player->getDefense());
			if (this->player->getHealth() <= 0)
			{
				break;
			} 
		}
		else if (response == "f")
		{
			this->textHandler->printText(std::string("\nYou fled from ") + enemy->getName());
			break;
		}
	}
}

void Game::PlayGame() {
	this->currentRoom = this->rooms[0];
	this->inputHandler->setObserver(this->rooms[0]);
	bool running = true;

	while (running && !this->player->isDead()) {
		this->textHandler->printText(std::string("What do you want to do? (help for help)"));
		std::string input = inputHandler->getInput();
		if (input == "help")
		{
			this->textHandler->printText
				(
					std::string("\nmove: move.\n")+
					std::string("look: look.\n")+
					std::string("move->enemy name: fight enemy.\n")+
					std::string("move->direction(north/east/south/west): move to the neighbouring room in that direction.\n")+
					std::string("move->obstacle name: attempt to traverse the obstacle.\n")+
					std::string("quit: quit the game.\n")
				);
		}
		else if (input == "quit")
		{
			running = false;
		}
		else
		{
			this->processInput(input);
		}
	}
	this->textHandler->printText(std::string("Qutting game..."));
	std::getline(std::cin, std::string());
}
