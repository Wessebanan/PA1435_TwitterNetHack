#include "Room.h"

void Room::exitRoom()
{
}

std::string Room::enterRoom()
{
	return std::string();
}

Room::Room()
{
	this->neighbours = nullptr;
	this->textHandler = nullptr; 
}

Room::Room(TextHandler* textHandler, int roomNumber)
{
	this->objects = new Obstacle*;
	this->neighbours = new Room*[4];
	for (int i = 0; i < 4; i++) {
		this->neighbours[i] = nullptr;
	}
	this->enemies = new Enemy*[10];
	if (roomNumber = 0) {
		// Hard coded room 0
		this->enemies[0] = new Enemy(this->textHandler, 30, 10, 7, "Meanboye");

	}
	else if (roomNumber = 1) {
		// Hard coded room 1
		this->enemies[0] = new Enemy(this->textHandler, 40, 15, 7, "A N G E R Y");
	}
	else if (roomNumber = 2) {
		// Hard coded room 2
		this->enemies[0] = new Enemy(this->textHandler, 15, 5, 0, "Mini Mean");
		this->enemies[1] = new Enemy(this->textHandler, 15, 5, 0, "Tiny Mad");
	}
	else if (roomNumber = 3) {
		// Hard coded room 3
		this->objects[0] = new Obstacle("Spikes", "Small metal objects", "Sharp metal spikes cover the ground", 20);
	}
	else {
		// Hard coded room 4
		this->enemies[0] = new Enemy(this->textHandler, 65, 15, 10, "Slayer");
	}



}

Room::~Room()
{
}

bool Room::lookat(std::string name)
{

	for (int i = 0; i < nrOfObj; i++) 
	{
		if (objects[i]->getName() == name)
			textHandler->printText("An object: " + objects[i]->getDetailed() + "\n"); 	return true;
		if (enemies[i]->getName() == name)
			textHandler->printText(enemies[i]->getDesc()); 	return true;
	}
	return std::string();
}

bool Room::enemyExists(std::string enemyName)
{
	return false;
}

bool Room::itemExists(std::string itemName)
{
	return false;
}

bool Room::obstacleExists(std::string obstName)
{
	return false;
}

bool Room::traverseObstacle(std::string obstName, Player *player)
{ 
	for (int i = 0; i < nrOfObj; i++) 
		if (objects[i]->getName() == obstName)
			player->damage(objects[i]->getDamage()); 	return true; 
	return false;

}

void Room::moveTo(std::string direction)
{
}

void Room::setNeighbour(Room * toSet, int neighbourNumber) {
	this->neighbours[neighbourNumber] = toSet;
}
