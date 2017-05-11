#ifndef ROOM_H
#define ROOM_H
#include<string>
#include "TextHandler.h"
class Room
{
private:
	Room** neighbours;
	void exitRoom();
	std::string enterRoom();
	TextHandler* textHandler;
public:
	Room();
	Room(TextHandler* &textHandler, int roomNumber, Room* neighbourN, Room* neighbourE, Room* neighbourS, Room* neighbourW);
	~Room();
	std::string lookat(std::string name); //Returns info on what is looked at.
	bool enemyExists(std::string enemyName);
	bool itemExists(std::string itemName);
	bool obstacleExists(std::string obstName);
	bool traverseObstacle(std::string obstName); //Attempt to tranverse an obstacle.
	void moveTo(std::string direction);
};
#endif