#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character
{
private:
	int score;
	void quit();
	void die();
public:
	Player();
	Player(TextHandler* textHandler, float health, float attack, float defense);
	~Player();
	bool processInput(std::string input);
};
#endif
