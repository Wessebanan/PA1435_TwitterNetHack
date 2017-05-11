#include "Enemy.h"

void Enemy::die()
{
	//TODO: Remove enemy.
	this->textHandler->printText(this->name + std::string(" has fallen to your might!"));
	std::getline(std::cin, std::string());
}

Enemy::Enemy()
	: Character()
{
	this->name = "";
}

Enemy::Enemy(TextHandler * textHandler, float health, float attack, float defense, std::string name, std::string desc)
	: Character (textHandler, health, attack, defense)
{
	this->name = name;
	this->enemyDesc = desc;
}

Enemy::~Enemy()
{
}

std::string Enemy::getName()
{
	return this->name;
}

std::string Enemy::getDesc()
{
	return this->enemyDesc;
}

