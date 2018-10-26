#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <stdlib.h>
#include <sstream>
#include <exception>
#include <iostream>

class Exception
{
public:


	class	BadCommandException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{ return ("Invalid command"); }
	};

	class	BadArgumentException : public std::exception
	{
		virtual const char *what() const throw()
		{ return ("Invalid argument"); }
	};

	class	Overflow : public std::exception
	{
	public:
		Overflow() : str(nullptr){}
		Overflow(std::string const &val, std::string const &t)
		{
			std::stringstream stream;
			stream << "Value " << val << " can't fit into " << t;
			std::string ret = stream.str();
			str = new char[ret.size() + 1];
			std::strcpy(str, ret.c_str());
		}
		~Overflow(){ delete(str); }

		virtual const char *what() const throw()
		{ return (str); }

	private:
		char 		*str;

	};

	class DivisionByZero : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{ return ("Division by Zero"); }
	};

	class PopFromEmptyStack : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{ return ("Can't pop from empty stack"); }
	};

	class NotEqual : public std::exception
	{
	public:
		NotEqual() : str(nullptr){}
		NotEqual(std::string argument, std::string value_in_stack)
		{
			std::stringstream stream;
			stream << "Value " << argument << " is not equal to " << value_in_stack;
			std::string ret = stream.str();
			str = new char[ret.size() + 1];
			std::strcpy(str, ret.c_str());
		}
		~NotEqual(){ delete(str); }

		virtual const char *what() const throw()
		{ return (str); }

	private:
		char 		*str;
	};
};

#endif