#include <cstdlib>
#include <new>
#include <cstring>
#include <string>
#include <iostream>

typedef	struct	Data
{
	std::string	s1;
	std::string	s2;
	int 		n;
}				Data;

Data	*deserialize(void *raw)
{
	Data	*data = new Data;
	for (int i = 0; i < 8; i++)
		data->s1.push_back(reinterpret_cast<char*>(raw)[i]);
	data->n = reinterpret_cast<int*>(raw)[8];
	for (int i = 12; i < 20; i++)
		data->s2.push_back(reinterpret_cast<char*>(raw)[i]);
	return data;
}

void	*serialize()
{
	char str[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	void *array = operator new(sizeof(char) * 16 + sizeof(int));
	for (int i = 0; i < 8; i++)
		reinterpret_cast<char*>(array)[i] = str[rand() % 62];
	reinterpret_cast<int*>(array)[8] = rand();
	for (int i = 12; i < 20; i++)
		reinterpret_cast<char*>(array)[i] = str[rand() % 62];
	return array;
}

int main()
{
	srand(time(0));
	void	*array = serialize();
	Data	*data = deserialize(array);

	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
}