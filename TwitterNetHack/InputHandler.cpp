#include "InputHandler.h"

void InputHandler::getInput() {
	std::string input;
	textHandler->printText(std::string("What do you want to do?"));
	std::getline(std::cin, input);

	for (int i = 0; i < nrOfObservers; i++) {
		// TODO
		// 
		// NOTIFY ALL OBSERVERS ABOUT INPUT
	}


}
