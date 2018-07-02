#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form() : name("name"), signRang(150), execRang(150), isSigned(false)
{}

Form::Form(Form &copy) : name(copy.getName()),
signRang(copy.getSignGrade()), execRang(copy.getExecGrade())
{ *this = copy; }

Form::Form(std::string newName, int newSignRang, int newExecRang) :
name(newName), signRang(newSignRang), execRang(newExecRang), isSigned(false)
{
	if (newSignRang > 150 || newExecRang > 150)
		throw GradeTooLowException();
	else if (newSignRang < 1 || newExecRang < 1)
		throw GradeTooHightException();
}

Form::~Form()
{}

Form	&Form::operator=(Form const &copy)
{
	this->isSigned = copy.getSign();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &form)
{
	if (form.getSign())
		o << form.getName() << " form is signed";
	else
	{
		o << "bureaucrat need do be at least " << form.getSignGrade()
		<< " to sign and at least " << form.getExecGrade() << 
		" to execute " << form.getName() << " form.";
	}
	return o;
}

const std::string	Form::getName() const
{ return this->name; }

int			Form::getSignGrade() const
{ return this->signRang; }

int			Form::getExecGrade() const
{ return this->execRang; }

bool		Form::getSign() const
{ return isSigned; }

void		Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= signRang)
		isSigned = true;
	else
		throw GradeTooLowException();
}
