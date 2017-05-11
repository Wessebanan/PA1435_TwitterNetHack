#pragma once
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "object.h" // Detta är Max inkompetens
#include "TextHandler.h"
#include "Room.h"

#define NR_OF_ROOMS 5

class Game {
private:
	TextHandler textHandler;
	InputHandler inputHandler;
	Player player;
	Room* rooms[NR_OF_ROOMS];

	void generateMaze();

public:
	Game();
	~Game();




};