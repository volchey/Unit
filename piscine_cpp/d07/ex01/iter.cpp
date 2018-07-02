#include <iostream>

class Data
{
public:
	Data() : x(1), y(2), c('c'){}
	int x;
	int y;
	char c;
};

std::ostream &operator<<(std::ostream & o, Data &obj)
{
	o << obj.x << obj.y << obj.c;
	return o;
}

template< typename T>

void	f(T element)
{
	std::cout << element << std::endl;
}

template< typename T, typename I>

void	iter(const T *array, I length, void (*f)(T))
{
	for (I i = 0; i < length; i++)
		f(array[i]);
}

int main()
{
	int	integers[5] = {0,1,2,3,4};
	char string[13] = "Hello world ";
	Data *data = new Data[5];
	std::string str[] = {"Hello", "World"};


	iter(integers, 5, &f);
	iter(string, 12, &f);
	iter(data, 5, &f);
	iter(str, 2, &f);
	return 0;
}