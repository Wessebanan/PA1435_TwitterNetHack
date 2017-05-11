#include "InputHandler.h"

InputHandler::InputHandler() {
	this->subGame = nullptr;
	this->subPlayer = nullptr;
	this->subRoom = nullptr;
}

InputHandler::InputHandler(TextHandler * textHandler) {
	this->textHandler = textHandler;
}

InputHandler::~InputHandler()
{
}

void InputHandler::setObserver(Game* observer) {


}

void InputHandler::setObserver(Room * observer)
{
}

void InputHandler::setObserver(Player * observer)
{
}

void InputHandler::getInput() {
	std::string input;
	bool r1 = false, r2 = false, r3 = false;
	textHandler->printText(std::string("What do you want to do?"));
	std::getline(std::cin, input);	
	if (this->subGame != nullptr) {
		r1 = this->subGame->processInput(input);
	}
	if (this->subPlayer != nullptr) {
		r2 = this->subPlayer->processInput(input);
	}
	if (this->subRoom != nullptr) {
		r3 = this->subRoom->processInput(input);
	}

	if (!r1 && !r2 && !r3) {
		this->textHandler->printText(std::string("Command not valid, please try again."));
	}


}
