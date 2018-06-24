#ifndef GAME_H
# define GAME_H

#include <string>

class Game
{
public:
    Game();
    ~Game();

    void    run();
	void	gameOver(WINDOW*);
};

#endif