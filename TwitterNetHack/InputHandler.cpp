#include "InputHandler.h"

InputHandler::InputHandler() {
	this->subPlayer = nullptr;
	this->subRoom = nullptr;
}

InputHandler::InputHandler(TextHandler * textHandler) {
	this->textHandler = textHandler;
}

InputHandler::~InputHandler()
{
}



void InputHandler::setObserver(Room * observer) {
	this->subRoom = observer;
}

void InputHandler::setObserver(Player * observer) {
	this->subPlayer = observer;
}

std::string InputHandler::getInput() {
	std::string input;
	bool r1 = false, r2 = false;
	textHandler->printText(std::string("What do you want to do?"));
	std::getline(std::cin, input);	
	if (this->subPlayer != nullptr) {
		r1 = this->subPlayer->processInput(input);
	}
	if (this->subRoom != nullptr) {
		r2 = this->subRoom->processInput(input);
	}

	if (!r1 && !r2) {
		this->textHandler->printText(std::string("Command not valid, please try again."));
	}

	return input;
}
