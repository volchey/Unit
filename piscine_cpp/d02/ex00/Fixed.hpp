
#ifndef FIXED_H
# define FIXED_H

class Fixed
{

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fpn);

	Fixed	&operator=(const Fixed &fpn);

	int		getRawBits()const;	
	void	setRawBits(int const raw);

private:
	int					_val;
	static const int	_size = 8;
};

#endif