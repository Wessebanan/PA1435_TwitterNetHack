#include <string>
#include <sstream>
#include <iostream>
#include "TextHandler.h"

class InputHandler {
private:
	int nrOfObservers;
	TextHandler* textHandler;


public:
	InputHandler(TextHandler* textHandler);
	~InputHandler();

	void setObserver(char PLACEHOLDER);
	void getInput();



};