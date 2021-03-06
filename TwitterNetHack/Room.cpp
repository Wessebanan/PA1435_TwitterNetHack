#include "Room.h"

void Room::exitRoom()
{
}

void Room::enterRoom()
{
	
}

Room::Room()
{
	this->neighbours = nullptr;
	this->textHandler = nullptr; 
}

Room::Room(TextHandler* textHandler, int roomNumber)
{
	roomNr = roomNumber;
	this->objects = new Obstacle*[10];
	this->neighbours = new Room*[4];
	for (int i = 0; i < 4; i++) {
		this->neighbours[i] = nullptr;
	}
	this->enemies = new Enemy*[10];
	if (roomNumber == 0) {
		// Hard coded room 0
		this->enemies[0] = new Enemy(this->textHandler, 30, 10, 7, "Meanboye", "A mean looking kinda guy.");
		nrOfenemies++;
	}
	else if (roomNumber == 1) {
		// Hard coded room 1
		this->enemies[0] = new Enemy(this->textHandler, 40, 15, 7, "A N G E R Y", "An increasingly frustrated individual");
		nrOfenemies++;
	}
	else if (roomNumber == 2) {
		// Hard coded room 2
		this->enemies[0] = new Enemy(this->textHandler, 15, 5, 0, "Mini Mean", "A short statured object of madness");
		nrOfenemies++;
		this->enemies[1] = new Enemy(this->textHandler, 15, 5, 0, "Tiny Mad", "Rage of the smaller variety");
		nrOfenemies++;
	}
	else if (roomNumber == 3) {
		// Hard coded room 3
		this->objects[0] = new Obstacle("Spikes", "Small metal objects", "Sharp metal spikes cover the ground", 20);
		nrOfObj++;
	}
	else {
		// Hard coded room 4
		this->enemies[0] = new Enemy(this->textHandler, 65, 15, 10, "Slayer", "The meanest and angriest of dudes");
		nrOfenemies++;
	} 
}

Room::~Room()
{
}

bool Room::lookat(std::string name)
{
	bool emptyRoomCheck = false;
	for (int i = 0; i < nrOfObj; i++)  
		if (objects[i]->getName() == name) { 
			textHandler->printText("An object: " + objects[i]->getDetailed() + "\n"); 
			emptyRoomCheck = true;
		}
	for (int i = 0; i < nrOfenemies; i++)
		if (enemies[i]->getName() == name) {
			textHandler->printText("An enemy: " + enemies[i]->getDesc() + "\n");
			emptyRoomCheck = true; 
		}
			
	if (!emptyRoomCheck)
		textHandler->printText(std::string("Can't find \"" + name + "\"\n"));

	return emptyRoomCheck;
}

bool Room::lookAround()
{
	bool emptyRoomCheck = false;

	for (int i = 0; i < nrOfObj; i++) 
		textHandler->printText("An object: " + objects[i]->getShort() + "\n"); emptyRoomCheck = true; 
	for (int i = 0; i < nrOfenemies; i++) 
		textHandler->printText("An enemy named: " + enemies[i]->getName() + "\n"); emptyRoomCheck = true;

	if (!emptyRoomCheck)
		textHandler->printText(std::string("The room is empty"));

	return emptyRoomCheck;
}

bool Room::enemyExists(std::string enemyName)
{
	bool check = false;
	for (int i = 0; i < nrOfenemies; i++)
		if (enemies[i]->getName() == enemyName)
			check = true;

	return check;
}

bool Room::itemExists(std::string itemName)
{
	return false; //No items in itteration 1
}

bool Room::obstacleExists(std::string obstName)
{
	bool check = false;
	for (int i = 0; i < nrOfObj; i++)
		if (objects[i]->getName() == obstName)
			check = true;

	return check;
}

bool Room::traverseObstacle(std::string obstName, Player *player)
{ 
	for (int i = 0; i < nrOfObj; i++) 
		if (objects[i]->getName() == obstName)
			player->damage(objects[i]->getDamage()); 	return true; 
	return false;

}

Room* Room::moveToRoom(std::string target)
{
	Room* targetRoom = this;

	if (target == "north")
	{
		if (roomNr == 0 || roomNr == 3)
			targetRoom = getNeighbour(0);
	}
	else if (target == "east")
	{
		if (roomNr == 1 || roomNr == 2)
			targetRoom = getNeighbour(1);
	}
	else if (target == "south")
	{
		if (roomNr == 1 || roomNr == 4)
			targetRoom = getNeighbour(2);
	}
	else if (target == "west")
	{
		if (roomNr == 1 || roomNr == 3)
			targetRoom = getNeighbour(3);
	} 
			
	textHandler->printText("You are now in room " + std::to_string(targetRoom->getRoomNr()));

	return targetRoom;
}

Enemy* Room::moveToEnemy(std::string target)
{  
	for (int i = 0; i < nrOfenemies; i++)
		if (enemies[i]->getName() == target)
			return enemies[i]; 

	return nullptr;
} 

Obstacle* Room::moveToObstacle(std::string target)
{
	for (int i = 0; i < nrOfObj; i++)
		if (objects[i]->getName() == target)
			return objects[i];

	return nullptr;
}
bool Room::processInput(std::string input)
{
	return false;
}

void Room::removeEnemy(std::string enemy)
{ 
	for (int i = 0; i < nrOfenemies; i++)
		if (enemies[i]->getName() == enemy) {
			delete enemies[i];
			if (nrOfenemies == 2 && i == 0)
			{
				enemies[0] = enemies[1];
			}
			nrOfenemies--; 
		} 
}
 
void Room::setNeighbour(Room * toSet, int neighbourNumber) {
	this->neighbours[neighbourNumber] = toSet;
}

Room * Room::getNeighbour(int neighbourNumber)
{
	return this->neighbours[neighbourNumber];
}
