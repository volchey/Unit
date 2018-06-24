#ifndef ASTEROID_H
# define ASTEROID_H

#include "Entity.hpp"

class Asteroid : public Entity
{
public:
	Asteroid();
	Asteroid(Asteroid &);
	Asteroid(int x, int y, char mark);
	~Asteroid();

	Asteroid &operator=(const Asteroid &);
	void update(int maxX, int maxY);
};

#endif