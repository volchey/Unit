#include "Entity.hpp"

Entity::Entity()
{
	this->x = 0;
	this->y = 0;
	this->mark = '>';
}

Entity::Entity(int x, int y, char mark)
{
	this->x = x;
	this->y = y;
	this->mark = mark;
}

Entity::~Entity()
{}

int		Entity::getX()
{ return this->x;}

int 	Entity::getY()
{ return this->y;}

char 	Entity::getMark()
{ return this->mark;}

void 	Entity::setX(int newX)
{ this->x = newX;}

void 	Entity::setY(int newY)
{ this->y = newY;}

void 	Entity::setMark(char newMark)
{ this->mark = newMark;}
