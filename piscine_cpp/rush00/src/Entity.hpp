#ifndef	ENTITY_H
# define ENTITY_H

class Entity
{
public:
	Entity();
	Entity(Entity&);
	Entity(int x, int y, char mark);
	~Entity();

	Entity	&operator=(const Entity &);
	int		getX();
	int		getY();
	char 	getMark();
	void 	setX(int newX);
	void 	setY(int newY);
	void 	setMark(char newMark);

protected:
	int		x;
	int		y;
	char	mark;
};

#endif