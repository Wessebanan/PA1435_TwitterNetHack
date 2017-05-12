#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Enemy.h"

class Player : public Character
{
private:
	int score;
	bool inCombat;
	void die();

	bool dead = false;
public:
	Player();
	Player(TextHandler* textHandler, float health, float attack, float defense);
	~Player();
	bool processInput(std::string input);
	bool isDead();
};
#endif
