#ifndef ROOM_H
#define ROOM_H
#include<string>
#include "Enemy.h"
#include "object.h"
#include "TextHandler.h"
class Room
{
private:
	Room** neighbours;
	Enemy** enemies;
	Object** objects;
	

	void exitRoom();
	std::string enterRoom();
	TextHandler* textHandler;
public:
	Room();
	Room(TextHandler* textHandler, int roomNumber);
	~Room();
	std::string lookat(std::string name); //Returns info on what is looked at.
	bool enemyExists(std::string enemyName);
	bool itemExists(std::string itemName);
	bool obstacleExists(std::string obstName);
	bool traverseObstacle(std::string obstName); //Attempt to tranverse an obstacle.
	void moveTo(std::string direction);

	void setNeighbour(Room* toSet, int neighbourNumber);
};
#endif