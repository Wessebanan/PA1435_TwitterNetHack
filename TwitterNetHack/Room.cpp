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

Room::Room(TextHandler *& textHandler, int roomNumber)
{
	this->neighbours = new Room*[4];

	if (roomNumber = 0) {
		// Hard coded room 0

	}
	else if (roomNumber = 1) {
		// Hard coded room 1

	}
	else if (roomNumber = 2) {
		// Hard coded room 2

	}
	else if (roomNumber = 3) {
		// Hard coded room 3

	}
	else {
		// Hard coded room 4

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

bool Room::traverseObstacle(std::string obstName)
{
	return false;
}

void Room::moveTo(std::string direction)
{
}

void Room::setNeighbour(Room * toSet, int neighbourNumber) {
	this->neighbours[neighbourNumber] = toSet;
}
