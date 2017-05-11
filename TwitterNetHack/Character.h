#ifndef CHARACTER_H
#define CHARACTER_H
#include "TextHandler.h"
class Character
{
private:
	float health;
	float attack;
	float defense;
	void die();

	TextHandler* textHandler;


public:
	Character();
	Character(TextHandler* &textHandler);
	~Character();
	void damage(int amount);
};
#endif