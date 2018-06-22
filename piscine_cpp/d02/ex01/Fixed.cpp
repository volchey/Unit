
#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int Fixed::_size = 8;

Fixed::Fixed(){

	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
	return;
}


Fixed::Fixed(const Fixed &fpn){
	std::cout << "Copy constructor called" << std::endl;
	*this = fpn;
	return;
}


Fixed::Fixed(const int	n){
	this->_val = n << _size;
	std::cout << "Int constuctor called" << std::endl;
	return;
}


Fixed::Fixed(const float n) {
	std::cout << "Float constuctor called" << std::endl;
	this->_val = roundf(n * (1 << _size));
	return;
}


Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return;
}


Fixed	& Fixed::operator=(const Fixed & fpn){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fpn)
		this->_val = fpn.getRawBits();
	return *this;
}


float	Fixed::toFloat() const{
	return ((float)(this->_val) / (1 << _size));
}


int		Fixed::toInt() const{
	return (int)(this->_val >> _size);
}


int		Fixed::getRawBits() const{
	return this->_val;
}


void	Fixed::setRawBits(int const raw){
	this->_val = raw;
}


std::ostream &	operator<<( std::ostream & o, Fixed const & fpn ) {
	o << fpn.toFloat();
	return o;
}
