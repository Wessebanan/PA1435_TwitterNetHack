#ifndef OBJECT_H
#define OBJECT_H

#include <string>

using namespace std;

class Object
{
private:
	string name; 
	string shortDesc;
	string detailedDesc;
public:
	Object(string name, string shortD, string detailedD );
	~Object() {};

	string getShort() { return shortDesc; };
	string getDetailed() { return detailedDesc; };
};


class Obstacle : public Object 
{
private:
	int damage;
public:
	Obstacle(string name, string shortD, string detailedD, int damage);
	~Obstacle() {};

	int getDamage() { return damage; };
};





#endif