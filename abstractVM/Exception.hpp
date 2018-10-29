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
		virtual const char *what() const throw();
	};

	class	BadArgumentException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class	Overflow : public std::exception
	{
	public:
		Overflow();
		Overflow(Overflow const &obj);
		Overflow(std::string const &, std::string const &);
		~Overflow();
		virtual const char *what() const throw();
		Overflow &operator=(Overflow const &obj);
	private:
		char 		*str;
	};

	class DivisionByZero : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class PopFromEmptyStack : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotEqual : public std::exception
	{
	public:
		NotEqual();
		NotEqual(NotEqual const &);
		NotEqual(std::string argument, std::string value_in_stack);
		~NotEqual(){ delete(str); }
		virtual const char *what() const throw();
		NotEqual &operator=(NotEqual const &);
	private:
		char 		*str;
	};
};

#endif