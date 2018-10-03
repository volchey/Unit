#include <iostream>
#include "AbstractVM.hpp"

AbstractVM::AbstractVM()
{
	functions = {{"push", push}, {"pop", pop}, {"dump", dump}, {"assert", assert},
				 {"add", add}, {"sub", sub}, {"mul", mul}, {"div", div},
				 {"mod", mod}, {"print", print}, {"exit", exit}, {";;", exit}};
}

AbstractVM::AbstractVM(const AbstractVM &obj)
{
	stack = obj.stack;
	functions = obj.functions;
}

AbstractVM::~AbstractVM()
{}

void	AbstractVM::push(std::string str)
{
	std::cout << "push called with argument: " << str << std::endl;
}

void	AbstractVM::pop(std::string str)
{
	std::cout << "pop called with argument: " << str << std::endl;
}

void	AbstractVM::dump(std::string str)
{std::cout << "dump called with argument: " << str << std::endl;}

void	AbstractVM::assert(std::string str)
{std::cout << "assert called with argument: " << str << std::endl;}

void	AbstractVM::add(std::string str)
{std::cout << "add called with argument: " << str << std::endl;}

void	AbstractVM::sub(std::string str)
{std::cout << "sub called with argument: " << str << std::endl;}

void	AbstractVM::mul(std::string str)
{std::cout << "mul called with argument: " << str << std::endl;}

void	AbstractVM::div(std::string str)
{std::cout << "div called with argument: " << str << std::endl;}

void	AbstractVM::mod(std::string str)
{std::cout << "mod called with argument: " << str << std::endl;}

void	AbstractVM::print(std::string str)
{std::cout << "print called with argument: " << str << std::endl;}

void	AbstractVM::exit(std::string str)
{std::cout << "exit called with argument: " << str << std::endl;}

AbstractVM &AbstractVM::operator=(AbstractVM const &obj)
{
	stack = obj.stack;
	functions = obj.functions;
	return (*this);
}

std::map<std::string, func_t > AbstractVM::getFunc() const
{
	return (functions);
}

std::list<IOperand *>	AbstractVM::getStack() const
{
	return (stack);
}

