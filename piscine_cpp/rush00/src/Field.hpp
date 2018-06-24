#ifndef FIELD_H
# define FIELD_H

#include <unistd.h>
#include "Asteroid.hpp"
#include "Rocket.hpp"
#include <ncurses.h>

class Field
{
public:
	Field();
	Field(Field &);
	Field(size_t, WINDOW *wnd);
	~Field();

	Field		&operator=(Field &);
	bool		update(size_t, int playerX, int p);
	size_t		getSize();
	Asteroid	*getAsteroides();

private:
	int		maxX;
	int		maxY;
	size_t	size;
	Asteroid *field;
};

#endif