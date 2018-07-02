#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <iostream>

template< typename T >
bool	easyfind(T const &array, int n)
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = array.end();
	for (it = array.begin(); it != ite; it++)
	{
		if (*it == n)
			return true;
	}
	return false;
}

#endif