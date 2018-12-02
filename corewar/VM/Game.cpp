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

Game::Game(Game &copy)
{
	*this = copy;
}

Game::~Game()
{
	endwin();
}

void Game::start()
{
	int	maxX = getmaxx(wnd);
	int maxY = getmaxy(wnd);

	mvprintw(maxY / 2, maxX / 3, "Welcome to our awesome Space Game;)");
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
	Field*	asteroids = new Field(40, wnd);
	int 	time = 0;
	refresh();

	mvaddch(player.getY(), player.getX(), player.getMark());
	refresh();

	bool	exit = false;
	int 	input;
	while (42)
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
			break;	time++;
		erase();
		player.display(maxX, maxY);
		refresh();
		player.updateRockets(*asteroids);
		refresh();
		if (!(asteroids->update(1, player.getX(), player.getY())))
			if (!gameOver(player))
				break;
		refresh();
		if (player.levelup(time))
		{
			mvprintw(getmaxy(wnd) / 2, getmaxx(wnd) / 2 - 2, "Level Up");
			refresh();
			usleep(1000000);
			delete asteroids;
			asteroids = new Field(50 + player.getLevel() * 20, wnd);
		}
		usleep(80000);
	}
	delete asteroids;
}

bool	Game::gameOver(Player &player)
{
	int input;
	int maxY = getmaxy(wnd);
	int maxX = getmaxx(wnd);

	if (player.getHealth() > 0)
	{
		player.takeDamage();
		return true;
	}
	mvprintw(maxY / 2 - 2, maxX / 5, "_____");
	mvprintw(maxY / 2 - 1, maxX / 5, "| ___/ __ _  _ __ ___    ___    ___  __   __ ___  _ __");
	mvprintw(maxY / 2, maxX / 5, "| | _     |_ | '_ ` _ \\\\  / _ \\\\   /     \\\\\\\\   // _ \\\\| |__|");
	mvprintw(maxY / 2 + 1, maxX / 5, "| |_\\\\\\\\| (_| || | | | | ||  __/  | (_) |\\\\ V /|  __/| |   ");
	mvprintw(maxY / 2 + 2, maxX / 5, "\\\\____/ \\\\__,_||_| |_| |_| \\\\___| \\\\___/  \\\\_/  \\\\___||_|   ");
	mvprintw(maxY / 2 + 5, maxX / 5, "Press \'q\' to quit or \'r\' to resume");
	while (1)
	{
		input = wgetch(wnd);
		switch (input)
		{
			case 'q':
				return false;
			case 'r': run(maxX, maxY);
				return false;
			case 'n':
				return true;
			default:
				break;
		}
	}
}