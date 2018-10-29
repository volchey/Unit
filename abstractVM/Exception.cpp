#include "Exception.hpp"

const char *Exception::BadCommandException::what() const throw()
{ return ("Invalid command"); }

const char *Exception::BadArgumentException::what() const throw()
{ return ("Invalid argument"); }

const char* Exception::DivisionByZero::what() const throw()
{ return ("Division by Zero"); }

const char* Exception::PopFromEmptyStack::what() const throw()
{ return ("Can't pop from empty stack"); }





Exception::Overflow::Overflow() : str(nullptr)
{}

Exception::Overflow::Overflow(const Exception::Overflow &obj)
{ str = obj.str; }

Exception::Overflow::Overflow(std::string const &val, std::string const &t)
{
	std::stringstream stream;
	stream << "Value " << val << " can't fit into " << t;
	std::string ret = stream.str();
	str = new char[ret.size() + 1];
	std::strcpy(str, ret.c_str());
}

Exception::Overflow::~Overflow()
{ delete(str); }

const char* Exception::Overflow::what() const throw()
{ return (str); }

Exception::Overflow& Exception::Overflow::operator=(const Exception::Overflow &obj)
{
	str = obj.str;
	return (*this);
}





Exception::NotEqual::NotEqual() : str(nullptr)
{}

Exception::NotEqual::NotEqual(const Exception::NotEqual &obj)
{ str = obj.str; }

Exception::NotEqual::NotEqual(std::string argument, std::string value_in_stack)
{
	std::stringstream stream;
	stream << "Value " << argument << " is not equal to " << value_in_stack;
	std::string ret = stream.str();
	str = new char[ret.size() + 1];
	std::strcpy(str, ret.c_str());
}

const char* Exception::NotEqual::what() const throw()
{ return (str); }

Exception::NotEqual& Exception::NotEqual::operator=(const Exception::NotEqual &obj)
{
	str = obj.str;
	return (*this);
}

