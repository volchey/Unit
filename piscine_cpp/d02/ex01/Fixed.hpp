
#ifndef FIXED_H
# define FIXED_H
#include <iostream>

class Fixed
{

public:
	Fixed();
	~Fixed();

	Fixed(const	int		n);
	Fixed(const float	n);
	Fixed(const Fixed	&fpn);

	Fixed	& operator=(const Fixed & fpn);

	float	toFloat()const;
	int		toInt()const;
	int		getRawBits()const;	
	void	setRawBits(int const raw);
	
private:
	int					_val;
	static const int	_size;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & fpn );


#endif