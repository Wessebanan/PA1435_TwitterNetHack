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
	Obstacle** objects;
	int nrOfObj = 0;
	int nrOfenemies = 0;

	int roomNr;

	void exitRoom();
	void enterRoom();
	TextHandler* textHandler;
public:
	Room();
	Room(TextHandler* textHandler, int roomNumber);
	~Room();
	bool lookat(std::string name); //Returns info on what is looked at.
	bool lookAround(); //Returns info on what is looked at.
	bool enemyExists(std::string enemyName);
	bool itemExists(std::string itemName);
	bool obstacleExists(std::string obstName);
	bool traverseObstacle(std::string obstName, Player *player); //Attempt to tranverse an obstacle.
	Room* moveTo(std::string target);

	bool processInput(std::string input);


	void setNeighbour(Room* toSet, int neighbourNumber);
	Room* getNeighbour(int neighbourNumber);
};
#endif