#include "Enemy.h"

void Enemy::die()
{
	//TODO: Remove enemy.
	//TODO: Inform player that enemy is dead and reward player with score and/or loot.
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

void Enemy::initiateCombat(Player * player)
{
}
