#ifndef PLAYER_H
# define PLAYER_H

#include "Entity.hpp"
#include "Rocket.hpp"
#include "Field.hpp"

class Player : public Entity
{
public:
	Player();
	Player(int x, int y, char mark);
	~Player();

	int		getHealth();
	void	takeDamage();
	void 	fire();
	void 	updateRockets(Field &asteroids);
	void	moveRight(int maxX);
	void	moveLeft();
	void	moveDown(int maxY);
	void	moveUp(int maxY);
	void	display();

private:
	int	health;
	Rocket rockets[3];
};

#endif