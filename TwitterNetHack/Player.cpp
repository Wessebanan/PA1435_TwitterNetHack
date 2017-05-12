#include "Player.h"

//void Player::quit()
//{
//	this->textHandler->printText(std::string("\nQuitting game...\n"));
//}

void Player::die()
{
	this->textHandler->printText(std::string("You died at the hands of Chestcunt"));
	std::getline(std::cin, std::string());
	this->dead = true;
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

bool Player::processInput(std::string input)
{
	return false;
}

bool Player::isDead()
{
	return this->dead;
}
