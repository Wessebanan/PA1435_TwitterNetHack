#include "object.h"

Object::Object(string name, string shortD, string detailedD)
{
	this->name = name;
	this->shortDesc = shortD;
	this->detailedDesc = detailedD;
};

Obstacle::Obstacle(string name, string shortD, string detailedD, int damage) 
	: Object(name, shortD, detailedD)
{
	this->damage = damage;
};