#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Player.h"
#include "TextHandler.h"
#include <string>
class Enemy : public Character
{
private:
public:
	Enemy();
	Enemy(TextHandler* textHandler);
	~Enemy();
	std::string name;
	void initiateCombat(Player* player);
};
#endif