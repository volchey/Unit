#ifndef ASTEROID_H
# define ASTEROID_H

#include "Entity.hpp"

class Asteroid : public Entity
{
public:
	Asteroid();
	Asteroid(int x, int y, char mark);
	~Asteroid();

	void update(int maxX, int maxY);
};

#endif