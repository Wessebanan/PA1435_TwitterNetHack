#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <sstream>
#include <iostream>
#include "TextHandler.h"
#include "Room.h"
#include "Player.h"

class InputHandler {
private:
	TextHandler* textHandler;
	Room* subRoom;
	Player* subPlayer;


public:
	InputHandler();
	InputHandler(TextHandler* textHandler);
	~InputHandler();

	void setObserver(Room* observer);
	void setObserver(Player* observer);
	std::string getInput();



};
#endif