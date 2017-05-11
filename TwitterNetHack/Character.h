#ifndef CHARACTER_H
#define CHARACTER_H
class Character
{
private:
	float health;
	float attack;
	float defense;
	void die();

public:
	Character();
	~Character();
	void damage(int amount);
};
#endif