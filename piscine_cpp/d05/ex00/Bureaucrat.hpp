#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &);
	Bureaucrat(std::string newName, int newRang);
	~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &);

	const std::string	getName() const;
	int					getGrade() const;

	void				decGrade();
	void				incGrade();

	class GradeTooHightException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("too hight rang");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("too low rang");
		}
	};

private:
	const std::string	name;
	int					rang;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bur);

#endif