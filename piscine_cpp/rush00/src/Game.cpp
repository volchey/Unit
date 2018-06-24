#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Game.hpp"
#include "Entity.hpp"
#include "Field.hpp"
#include "Player.hpp"

WINDOW	*wnd;

Game::Game()
{
	srand(time(0));
	wnd = initscr();
	cbreak();
	noecho();
	nodelay(wnd, true);
	clear();
	refresh();

	keypad(wnd, true);
	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));

	attron(A_BOLD);
	box(wnd, 0, 0);
	attroff(A_BOLD);
}

Game::~Game()
{
	endwin();
}

void Game::start()
{
	int	maxX = getmaxx(wnd);
	int maxY = getmaxy(wnd);
	std::string text= "Welcome to our awesome Space Game;)";

	move(maxY / 2, maxX / 3);
	for (int i = 0; i < (int)text.size(); i++)
	{
		addch(text[i]);
	}
	refresh();
	usleep(1000000);
	erase();
	mvaddch(maxY / 2, maxX / 2, '3');
	refresh();
	usleep(1000000);
	erase();
	mvaddch(maxY / 2, maxX / 2, '2');
	refresh();
	usleep(1000000);
	erase();
	mvaddch(maxY / 2, maxX / 2, '1');
	refresh();
	usleep(1000000);
	werase(wnd);
	run(maxX, maxY);
}

void Game::run(int const maxX, int const maxY)
{
	Player	player(maxX / 2, maxY / 2, 'A');
	Field	asteroids(200, wnd);

	refresh();

	mvaddch(player.getY(), player.getX(), player.getMark());
	refresh();

	bool	exit = false;
	int 	input;
	while (1)
	{
		input = getch();
		switch (input)
		{
			case 'q': exit = true;
				break;
			case KEY_UP: player.moveUp(getmaxy(wnd));
				break;
			case KEY_LEFT: player.moveLeft();
				break;
			case KEY_RIGHT: player.moveRight(getmaxx(wnd));
				break;
			case KEY_DOWN: player.moveDown(getmaxy(wnd));
				break;
			case ' ': player.fire();
			default:
				break;
		}
		if (exit)
			break;
		werase(wnd);
		player.display();
		player.updateRockets(asteroids);
		if (!(asteroids.update(1, player.getX(), player.getY())))
			if (!gameOver())
				break;
		usleep(100000);
		refresh();
	}
}

bool	Game::gameOver()
{
	int input;
	int maxY = getmaxy(wnd);
	int maxX = getmaxx(wnd);

	mvprintw(maxY / 2 - 2, maxX / 4, "_____");
	mvprintw(maxY / 2 - 1, maxX / 4, "| ___/ __ _  _ __ ___    ___    ___  __   __ ___  _ __");
	mvprintw(maxY / 2, maxX / 4, "| | _     |_ | '_ ` _ \\\\  / _ \\\\   /     \\\\\\\\   // _ \\\\| |__|");
	mvprintw(maxY / 2 + 1, maxX / 4, "| |_\\\\\\\\| (_| || | | | | ||  __/  | (_) |\\\\ V /|  __/| |   ");
	mvprintw(maxY / 2 + 2, maxX / 4, "\\\\____/ \\\\__,_||_| |_| |_| \\\\___| \\\\___/  \\\\_/  \\\\___||_|   ");
	mvprintw(maxY / 2 + 5, maxX / 4, "Press \'q\' to quit or \'r\' to resume");
	while (1)
	{
		input = wgetch(wnd);
		switch (input)
		{
			case 'q':
				return false;
			case 'r':
				return true;
			default:
				break;
		}
	}
}