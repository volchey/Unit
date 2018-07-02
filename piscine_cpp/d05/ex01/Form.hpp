#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Form
{
public:
	Form();
	Form(Form &);
	Form(std::string newName, int newSignRang, int newExecRang);
	~Form();

	Form	&operator=(Form const &);

	const std::string	getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getSign() const;
	void				beSigned(Bureaucrat);

	class GradeTooHightException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("too hight Grade");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("too low Grade");
		}
	};

private:
	const std::string	name;
	const int			signRang;
	const int			execRang;
	bool				isSigned;
};

std::ostream	&operator<<(std::ostream &o, Form const &bur);

#endif