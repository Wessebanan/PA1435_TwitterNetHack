#ifndef CHARACTER_H
#define CHARACTER_H
#include "TextHandler.h"
class Character
{
private:
	virtual void die() = 0;
protected:
	float health;
	float attack;
	float defense;
	TextHandler* textHandler;
public:
	Character();
	Character(TextHandler* textHandler, float health, float attack, float defense);
	~Character();
	void damage(float amount);
	float getHealth();
	float getAttack();
	float getDefense();
};
#endif