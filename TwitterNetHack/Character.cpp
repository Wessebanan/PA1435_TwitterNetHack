#include "Character.h"

Character::Character()
{
	this->health = 0;
	this->attack = 0;
	this->defense = 0;
	this->textHandler = nullptr;
}

Character::Character(TextHandler * textHandler, float health, float attack, float defense)
{
	this->textHandler = textHandler;
}

Character::~Character()
{
}

void Character::damage(float amount)
{
	this->health -= amount;
	if (health <= 0)
	{
		this->die();
	}
}
