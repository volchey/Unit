#include "Rocket.hpp"

Rocket::Rocket()
{
	this->x = 0;
	this->y = 0;
	this->mark = ' ';
	used = false;
}
Rocket::~Rocket()
{}

void Rocket::update()
{
	this->y -= 2;
	if (y <= 1)
	{
		this->mark = ' ';
		this->used = false;
	}
}

bool Rocket::getUsage()
{ return used; }

void Rocket::setUsage(bool newUsage)
{
	used = newUsage;
}