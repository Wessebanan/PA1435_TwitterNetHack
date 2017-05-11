#include "Room.h"

void Room::exitRoom()
{
}

void::enterRoom()
{
	
}

Room::Room()
{
	this->neighbours = nullptr;
	this->textHandler = nullptr; 
}

Room::Room(TextHandler* textHandler, int roomNumber)
{
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

	}
	else {
		// Hard coded room 4
		this->enemies[0] = new Enemy(this->textHandler, 65, 15, 10, "Slayer");
	}



}

Room::~Room()
{
}

std::string Room::lookat(std::string name)
{
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
