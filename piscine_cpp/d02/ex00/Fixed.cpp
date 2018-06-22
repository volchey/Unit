
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(){

	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}


Fixed::Fixed(const Fixed &fpn){

	std::cout << "Copy constructor called" << std::endl;
	*this = fpn;
}


Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}


Fixed	&Fixed::operator=(const Fixed &fpn){

	std::cout << "Assignation operator called" << std::endl;
	this->_val = fpn.getRawBits();
	return *this;
}


int		Fixed::getRawBits() const{

	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}


void	Fixed::setRawBits(int const raw){

	this->_val = raw;
}
