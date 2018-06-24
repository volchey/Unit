#include <ncurses.h>
#include <cstdlib>
#include "Player.hpp"

Player::Player()
{
	health = 5;
	level = 1;
}

Player::Player(Player &copy)
{ *this = copy;}

Player::Player(int x, int y, char mark)
{
	health = 5;
	level = 1;
	this->x = x;
	this->y = y;
	this->mark = mark;
}

Player::~Player()
{}

Player	&Player::operator=(const Player &copy)
{
	this->health = copy.health;
	this->level = copy.level;
	return *this;
}

int Player::getHealth()
{ return this->health; }

void Player::takeDamage()
{
	if (this->health > 0)
	{
		this->health--;
	}
}

int Player::getLevel()
{ return this->level;}

bool Player::levelup(int &time)
{
	if (time == level * 200)
	{
		level++;
		time = 0;
		return true;
	}
	return false;
}

void Player::fire()
{
	for (int i = 0; i < 3; i++)
	{
		if (!rockets[i].getUsage())
		{
			system("afplay music/Beep6.wav &");
			rockets[i].setUsage(true);
			rockets[i].setMark('!');
			rockets[i].setX(this->x);
			rockets[i].setY(this->y);
			break;
		}
	}
}

void Player::updateRockets(Field &asteroides)
{
	for (int i = 0; i < 3; i++)
	{
		if (rockets[i].getUsage())
		{
			rockets[i].update();
			attron(COLOR_PAIR(4));
			mvaddch(rockets[i].getY(), rockets[i].getX(), rockets[i].getMark());
			attron(COLOR_PAIR(1));
		}
		for (int a = 0; a < (int)asteroides.getSize(); a++)
		{
			 if ((rockets[i].getX() == asteroides.getAsteroides()[a].getX()
				|| rockets[i].getX() + 1 == asteroides.getAsteroides()[a].getX()
				|| rockets[i].getX() - 1 == asteroides.getAsteroides()[a].getX())
				&& (rockets[i].getY() == asteroides.getAsteroides()[a].getY()
				|| rockets[i].getY() + 1 == asteroides.getAsteroides()[a].getY()
				|| rockets[i].getY() - 1 == asteroides.getAsteroides()[a].getY())
				&& rockets[i].getMark() != ' ')
			 {
				 rockets[i].setMark(' ');
				 asteroides.getAsteroides()[a].setMark(' ');
			 }
		}
	}
}

void Player::display(int maxX, int maxY)
{
	attron(COLOR_PAIR(2));
	mvaddch(this->y, this->x + 1, '>');
	mvaddch(this->y, this->x - 1, '<');
	mvaddch(this->y, this->x, this->mark);
	mvprintw(maxY - 1, 0, "level: %d", level);
	mvprintw(maxY - 1, maxX - 10, "health: %d", health);
	attron(COLOR_PAIR(1));
}

void Player::moveDown(int maxY)
{
	if (this->y < maxY - 1)
		this->y++;
}

void Player::moveRight(int maxX)
{
	if (this->x < maxX - 2)
		this->x += 2;
}

void Player::moveLeft()
{
	if (this->x > 1)
		this->x -= 2;
}

void Player::moveUp(int maxY)
{
	if (this->y > maxY / 2)
		this->y--;
}
