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
}

Room::Room(TextHandler *& textHandler)
{
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
