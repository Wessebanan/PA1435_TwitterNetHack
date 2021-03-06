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
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}

Character::~Character()
{
}

void Character::damage(float amount)
{
	float dmg = amount;
	if (dmg < 0)
	{
		dmg = 0;
	}
	this->health -= dmg;

	textHandler->printText("Health: " + std::to_string(int(health)) + "\n");
	if (health <= 0)
	{
		this->die();
	}
}

float Character::getHealth()
{
	return this->health;
}

float Character::getAttack()
{
	return this->attack;
}

float Character::getDefense()
{
	return this->defense;
}
