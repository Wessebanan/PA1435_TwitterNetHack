#include "Player.h"

void Player::quit()
{
}

void Player::die()
{
	//TODO: Inform player that they have died (textHandler).
	system("pause");
	this->quit();
}

Player::Player()
{
}

Player::Player(TextHandler * textHandler, float health, float attack, float defense) 
	: Character(textHandler, health, attack, defense)
{
	this->score = 0;
}

Player::~Player()
{
}