#include <cstdlib>
#include "Asteroid.hpp"

Asteroid::Asteroid()
{
	this->x = 0;
	this->y = 0;
	this->mark = ' ';
}

Asteroid::Asteroid(Asteroid &copy)
{ *this = copy;}

Asteroid::Asteroid(int x, int y, char mark)
{
	this->x = x;
	this->y = y;
	this->mark = mark;
}

Asteroid::~Asteroid()
{}

Asteroid &Asteroid::operator=(const Asteroid &)
{ return *this;}

void Asteroid::update(int maxX, int maxY)
{
	this->y++;
	if (this->y >= maxY - 1)
	{
		this->y = 0;
		this->x = rand() % maxX;
	}
}