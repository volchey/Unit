#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include <sstream>
#include "IOperand.hpp"

class OperandFactory
{
public:
    OperandFactory();
    OperandFactory(const OperandFactory &);
    ~OperandFactory();

class	Overflow : public std::exception
{
public:
	Overflow() : value(nullptr), type(nullptr){}
	Overflow(std::string const val, std::string const t) : value(val), type(t){}

	virtual const char *what() const throw()
	{
		std::stringstream stream;
		stream << "Value " << value << "can't fit into " << type << std::endl;
		std::string ret = stream.str();
		return (ret.c_str());
	}

private:
	std::string value;
	std::string type;
};

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};

#endif