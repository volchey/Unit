#ifndef PLAYER_H
# define PLAYER_H

#include "Entity.hpp"
#include "Rocket.hpp"
#include "Field.hpp"

class Player : public Entity
{
public:
	Player();
	Player(Player &);
	Player(int x, int y, char mark);
	~Player();

	Player	&operator=(const Player &);

	void	takeDamage();
	void 	fire();
	void 	updateRockets(Field &asteroids);
	void	moveRight(int maxX);
	void	moveLeft();
	void	moveDown(int maxY);
	void	moveUp(int maxY);
	void	display(int maxX, int maxY);

	int		getHealth();
	int 	getLevel();
	bool	levelup(int &time);

private:
	int	health;
	int level;
	Rocket rockets[3];
};

#endif