#include <iostream>
#include "AbstractVM.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

typedef void (AbstractVM::*func_t)(std::string);

AbstractVM::AbstractVM()
{
	functions = {{"push", &AbstractVM::push},
			  {"pop", &AbstractVM::pop},
			  {"dump", &AbstractVM::dump},
			  {"assert", &AbstractVM::assert},
			  {"add", &AbstractVM::add},
			  {"sub", &AbstractVM::sub},
			  {"mul", &AbstractVM::mul},
			  {"div", &AbstractVM::div},
			  {"mod", &AbstractVM::mod},
			  {"print", &AbstractVM::print},
			  {"exit", &AbstractVM::exit},
			  {";;", &AbstractVM::exit}};
}

AbstractVM::AbstractVM(const AbstractVM &obj)
{
	stack = obj.stack;
	functions = obj.functions;
}

AbstractVM::~AbstractVM()
{
	for (auto i = stack.end(); i != stack.begin();)
	{
		--i;
		delete *i;
	}
}

void	AbstractVM::push(std::string str)
{
	std::string		types[] = {"int8", "int16", "int32", "float", "double"};
	std::size_t 	l_bracket = 0;
	std::size_t		r_bracket = 0;
	std::string		type;
	std::string		value;

	l_bracket = str.find('(');
	r_bracket = str.find(')');

	if (l_bracket == std::string::npos || r_bracket == std::string::npos)
		throw Exception::BadArgumentException();
	type = str.substr(0, l_bracket);
	value = str.substr(l_bracket + 1, r_bracket - l_bracket - 1);
	for (int i = 0; i <= Double; ++i)
	{
		if (types[i] == type)
		{
			stack.push_back(factory.createOperand(eOperandType(i), value));
			return;
		}
	}

	throw Exception::BadArgumentException();
}

void	AbstractVM::pop(std::string str)
{
    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	stack.pop_back();
}

void	AbstractVM::dump(std::string str)
{
	auto i = stack.end();

    if (!str.empty())
        throw Exception::BadArgumentException();
	i--;
	while (i != stack.begin())
	{
		std::cout << (*i)->toString() << std::endl;
		i--;
	}
	std::cout << (*i)->toString() << std::endl;
}

void	AbstractVM::assert(std::string str)
{
	push(std::move(str));
	std::string argument = stack.back()->toString();
	stack.pop_back();
	if (argument != stack.back()->toString())
		throw Exception::NotEqual(argument, stack.front()->toString());
}

void	AbstractVM::add(std::string str)
{
	IOperand const *first;
	IOperand const *second;

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	first = stack.back();
	stack.pop_back();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	second = stack.back();
	stack.pop_back();
	stack.push_back(*first + *second);
}

void	AbstractVM::sub(std::string str)
{
	IOperand const *first;
	IOperand const *second;

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	first = stack.back();
	stack.pop_back();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	second = stack.back();
	stack.pop_back();
	stack.push_back(*second - *first);
}

void	AbstractVM::mul(std::string str)
{
	IOperand const *first;
	IOperand const *second;

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	first = stack.back();
	stack.pop_back();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	second = stack.back();
	stack.pop_back();
	stack.push_back(*first * *second);
}

void	AbstractVM::div(std::string str)
{
	IOperand const *first;
	IOperand const *second;

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	first = stack.back();
	stack.pop_back();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	second = stack.back();
	stack.pop_back();
	stack.push_back(*second / *first);
}

void	AbstractVM::mod(std::string str)
{
	IOperand const *first;
	IOperand const *second;

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	first = stack.back();
	stack.pop_back();
	if (stack.empty())
		throw Exception::PopFromEmptyStack();
	second = stack.back();
	stack.pop_back();
	stack.push_back(*second % *first);
}

void	AbstractVM::print(std::string str)
{
	IOperand const *var = stack.back();

    if (!str.empty())
        throw Exception::BadArgumentException();
	if (var->getPrecision() == Int8)
		std::cout << var->toString() << std::endl;
	else
		throw std::exception();
}

void	AbstractVM::exit(std::string str)
{
    if (!str.empty())
        throw Exception::BadArgumentException();
	std::exit(1);
}

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
