#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Player.h"
#include <string>
class Enemy : public Character
{
private:
	void die();
	std::string name;
	std::string enemyDesc;

	bool dead = false;
public:
	Enemy();
	Enemy(TextHandler* textHandler, float health, float attack, float defense, std::string name, std::string desc);
	~Enemy();

	std::string getName();
	std::string getDesc();

	bool isDead() {return dead; };
};
#endif