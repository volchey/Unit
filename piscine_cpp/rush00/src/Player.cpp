#include <ncurses.h>
#include "Player.hpp"

Player::Player()
{
	health = 1;
}

Player::Player(int x, int y, char mark)
{
	this->x = x;
	this->y = y;
	this->mark = mark;
}

Player::~Player()
{}

int Player::getHealth()
{ return this->health; }

void Player::takeDamage()
{
	if (health > 0)
	{
		health--;
	}
}

void Player::fire()
{
	for (int i = 0; i < 5; i++)
	{
		if (!rockets[i].getUsage())
		{
			rockets[i].setUsage(true);
			rockets[i].setMark('!');
			rockets[i].setX(this->x);
			rockets[i].setY(this->y);
			return;
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

void Player::display()
{
	attron(COLOR_PAIR(2));
	mvaddch(this->y, this->x + 1, '>');
	mvaddch(this->y, this->x - 1, '<');
	mvaddch(this->y, this->x, this->mark);
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
