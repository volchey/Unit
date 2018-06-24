#ifndef GAME_H
# define GAME_H

#include <string>
#include <ncurses.h>

class Game
{
public:
    Game();
    ~Game();

    void    run(int maxX, int maxY);
	bool	gameOver();
	void	start();
};

#endif