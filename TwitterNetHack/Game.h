#pragma once
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "object.h" // Detta är Max inkompetens
#include "TextHandler.h"
#include "Room.h"


class Game {
private:
	TextHandler textHandler;
	InputHandler inputHandler;
	Player player;


	void generateMaze();

public:
	Game();
	~Game();




};