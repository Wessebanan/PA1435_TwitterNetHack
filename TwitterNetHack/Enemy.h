#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Player.h"
#include <string>
class Enemy : public Character
{
private:
	void die();
public:
	Enemy();
	Enemy(TextHandler* textHandler, float health, float attack, float defense, std::string name);
	~Enemy();
	std::string name;
	void initiateCombat(Player* player);
};
#endif