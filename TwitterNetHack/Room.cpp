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

Room::Room(TextHandler *& textHandler)
{
	this->neighbours = new Room*[4];

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
