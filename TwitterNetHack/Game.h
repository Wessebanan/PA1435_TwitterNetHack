#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "object.h" // Detta är Max inkompetens
#include "TextHandler.h"
#include "Room.h"

#define NR_OF_ROOMS 5

class Game {
private:
	TextHandler* textHandler;
	InputHandler* inputHandler;
	Player* player;
	Room* rooms[NR_OF_ROOMS];
	Room* currentRoom;

	void generateMaze();

public:
	Game();
	~Game();
	void battleSequence(Enemy * enemy);
	void PlayGame();
	bool processInput(std::string input);



};
#endif