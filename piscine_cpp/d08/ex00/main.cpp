#include "easyfind.hpp"
#include <list>
#include <map>
#include <vector>

int main()
{
	std::list<int>				lst1;
	std::map<std::string, int>	map1;
	std::vector<int>			v1(42, 100);

	for (int i = 0; i < 5; i++)
	{
		lst1.push_back(i);
	}

	map1["first"] = 42;
	map1["second"] = 43;
	if (easyfind(lst1, 3))
		std::cout << "found" << std::endl;
	// easyfind(map1, 3);
	if (easyfind(v1, 100))
		std::cout << "found" << std::endl;

}