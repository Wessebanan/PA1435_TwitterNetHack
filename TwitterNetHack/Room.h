#ifndef ROOM_H
#define ROOM_H
#include<string>
class Room
{
private:
	Room* neighbours;
	void exitRoom();
	std::string enterRoom();
public:
	Room();
	~Room();
	std::string lookat(std::string name); //Returns info on what is looked at.
	bool enemyExists(std::string enemyName);
	bool itemExists(std::string itemName);
	bool obstacleExists(std::string obstName);
	bool traverseObstacle(std::string obstName); //Attempt to tranverse an obstacle.
	void moveTo(std::string direction);
};
#endif