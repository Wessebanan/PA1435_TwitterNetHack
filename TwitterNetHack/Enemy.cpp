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

Enemy::Enemy(TextHandler * textHandler, float health, float attack, float defense, std::string name)
	: Character (textHandler, health, attack, defense)
{
	this->name = name;
}

Enemy::~Enemy()
{
}

void Enemy::initiateCombat(Player * player)
{
}
