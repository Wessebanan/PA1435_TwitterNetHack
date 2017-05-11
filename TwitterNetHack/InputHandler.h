#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <sstream>
#include <iostream>
#include "TextHandler.h"
#include "Game.h"
#include "Room.h"
#include "Player.h"

class InputHandler {
private:
	TextHandler* textHandler;
	Game* subGame;
	Room* subRoom;
	Player* subPlayer;


public:
	InputHandler();
	InputHandler(TextHandler* textHandler);
	~InputHandler();

	void setObserver(Game* observer);
	void setObserver(Room* observer);
	void setObserver(Player* observer);
	void getInput();



};
#endif