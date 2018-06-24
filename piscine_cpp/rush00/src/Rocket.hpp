
#ifndef	ROCKET_H
# define ROCKET_H

#include "Entity.hpp"

class Rocket : public Entity
{
public:
	Rocket();
	~Rocket();

	void	update();
	bool	getUsage();
	void 	setUsage(bool);

private:
	bool	used;
};

#endif