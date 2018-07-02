#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : name("name"), rang(150)
{
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{ *this = copy; }

Bureaucrat::Bureaucrat(std::string newName, int newRang) : name(newName), rang(newRang)
{
	if (newRang > 150)
		throw GradeTooLowException();
	else if (newRang < 1)
		throw GradeTooHightException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->rang = copy.rang;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return o;
}

const std::string	Bureaucrat::getName() const
{ return this->name; }

int			Bureaucrat::getGrade() const
{ return rang; }

void		Bureaucrat::decGrade()
{
	if (rang > 149)
		throw Bureaucrat::GradeTooLowException();
	rang++;
}

void		Bureaucrat::incGrade()
{
	if (rang < 2)
		throw Bureaucrat::GradeTooHightException();
	rang--;
}
