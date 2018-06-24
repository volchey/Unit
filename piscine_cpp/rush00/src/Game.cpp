#include <string>
#include <ncurses.h>
#include "Game.hpp"
#include "Entity.hpp"
#include <unistd.h>
#include "Field.hpp"
#include "Rocket.hpp"
#include "Player.hpp"

WINDOW	*wnd;

Game::Game()
{
	srand(time(0));
	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();

	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);

	if(!has_colors()) {
		endwin();
		printf("ERROR: Terminal does not support color.\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));

	attron(A_BOLD);
	box(wnd, 0, 0);
	attroff(A_BOLD);
}

Game::~Game()
{
	endwin();
}

void Game::run()
{
	int	maxX = getmaxx(wnd);
	int maxY = getmaxy(wnd);
	Player	player(maxX / 2, maxY / 2, 'A');
	Field	asteroids(200, wnd);

	refresh();

	mvaddch(player.getY(), player.getX(), player.getMark());
	refresh();

	bool	exit = false;
	int 	input;
	while (1)
	{
		input = wgetch(wnd);
		switch (input)
		{
			case 'q': exit = true;
				break;
			case KEY_UP: player.moveUp(maxY);
				break;
			case KEY_LEFT: player.moveLeft();
				break;
			case KEY_RIGHT: player.moveRight(maxX);
				break;
			case KEY_DOWN: player.moveDown(maxY);
				break;
			case ' ': player.fire();
			default:
				break;
		}
		if (exit)
			break;
		werase(wnd);
		mvaddch(player.getY(), player.getX() + 1, '>');
		mvaddch(player.getY(), player.getX() - 1, '<');
		mvaddch(player.getY(), player.getX(), player.getMark());
		player.updateRockets(asteroids);
		if (!(asteroids.update(1, player.getX(), player.getY())))
			gameOver(wnd);
		usleep(100000);
		refresh();
	}
}

void	Game::gameOver(WINDOW *wnd)
{
	int input;

	while (1)
	{
		input = wgetch(wnd);
		switch (input)
		{
			case 'q': exit(1);
			case 'r':
				return;
			default:
				break;
		}
	}
}