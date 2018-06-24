#include "Field.hpp"
#include "Asteroid.hpp"
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

Field::Field()
{}

Field::Field(Field &copy)
{ *this = copy;}

Field::Field(size_t count, WINDOW *wnd)
{
	this->size = count;
	this->maxX = getmaxx(wnd);
	this->maxY = getmaxy(wnd);
	field = new Asteroid[count];
}

Field::~Field()
{
	delete [] this->field;
}

Field	&Field::operator=(Field &copy)
{
	this->maxX = copy.maxX;
	this->maxY = copy.maxY;
	this->size = copy.size;
	this->field = copy.field;
	return *this;
}

bool	Field::update(size_t count, int playerX, int playerY)
{
	int k = 0;

	for (int i = 0; i < (int)this->size; i++)
	{
		if (field[i].getMark() != ' ')
		{
			field[i].update(this->maxX, this->maxY);
			attron(COLOR_PAIR(3));
			mvaddch(field[i].getY(), field[i].getX(), field[i].getMark());
			attron(COLOR_PAIR(1));
			if (field[i].getY() == playerY && (field[i].getX() == playerX
					|| field[i].getX() + 1 == playerX
											   || field[i].getX() - 1 == playerX))
			{
				system("afplay music/Explosion6.wav &");
				return false;
			}
		}
		else if (k < (int)count)
		{
			field[i].setX(rand() % maxX);
			field[i].setY(0);
			field[i].setMark('*');
			k++;
		}
		refresh();
	}
	return true;
}

size_t	Field::getSize()
{ return this->size; }

Asteroid	*Field::getAsteroides()
{ return this->field; }