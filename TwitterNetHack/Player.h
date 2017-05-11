#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
class Player : public Character
{
private:
	int score;
	void quit();
public:
	Player();
	~Player();
};
#endif
