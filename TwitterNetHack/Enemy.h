#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Player.h"
#include <string>
class Enemy : public Character
{
private:
public:
	std::string name;
	void initiateCombat(Player* player);
};
#endif