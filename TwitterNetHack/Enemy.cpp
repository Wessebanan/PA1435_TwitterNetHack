#include "Enemy.h"

Enemy::Enemy() 
	: Character()
{
}

Enemy::Enemy(TextHandler * textHandler) 
	: Character (textHandler)
{

}

Enemy::~Enemy()
{
}

void Enemy::initiateCombat(Player * player)
{
}
