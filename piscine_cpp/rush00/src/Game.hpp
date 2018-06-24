#ifndef GAME_H
# define GAME_H

#include <string>
#include <ncurses.h>
#include "Player.hpp"

class Game
{
public:
    Game();
	Game(Game &copy);
    ~Game();

    void    run(int maxX, int maxY);
	bool	gameOver(Player &player);
	void	start();
};

#endif