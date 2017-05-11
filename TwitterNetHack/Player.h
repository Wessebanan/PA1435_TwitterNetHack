#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Enemy.h"

class Player : public Character
{
private:
	int score;
	bool inCombat;
	void quit();
	void die();
public:
	Player();
	Player(TextHandler* textHandler, float health, float attack, float defense);
	~Player();
};
#endif
