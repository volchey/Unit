#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

void	check_Form()
{
	try
	{
		Form form("form228", 153, 153)
	}
	catch (std::exception & e)
	{
		std::cout << e.who() << std::endl;
	}
}

void	check_Bureaucrat()
{
	Bureaucrat bureaucrat("name", 149);

	try
	{
		bureaucrat.decGrade();
		bureaucrat.decGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("name", 153);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;

	Bureaucrat bob("bob", 1);

	try
	{
		bob.incGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bob("bob", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bob << std::endl;
}

int main()
{
	check_Bureaucrat();
	check_Form();
}
	