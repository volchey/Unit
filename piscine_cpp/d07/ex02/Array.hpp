#ifndef ARRAY_T
# define ARRAY_T

#include <iostream>

template<typename T = int>
class Array
{
public:
	Array< T >()
	{
		array = new T;
		_size = 0;
	}

	Array< T >(unsigned int size)
	{
		array = new T[size];
		// for (unsigned int i = 0; i < size; i++)
		// 	array[i] = *(new T());
		_size = size;
	}

	Array< T >(Array< T > &copy) { *this = copy; }

	~Array< T >() { delete [] array; }

	Array< T > &operator=(Array< T > const &copy)
	{
		delete [] array;
		array = new T[copy._size];
		this->_size = copy._size;
		for (unsigned int i = 0; i < copy._size; i++)
			array[i] = copy.array[i];
		return (*this);
	}

	T	&operator[](unsigned int i)
	{
		if (i > _size)
			throw std::exception();
		return (array[i]);
	}

	unsigned int size()
	{
		return _size;
	}
	
private:
	T *array;
	unsigned int _size;
};

#endif