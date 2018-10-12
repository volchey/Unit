#include "Operand.hpp"

extern OperandFactory factory;

Operand::Operand() : value(nullptr), type(Int8)
{}

Operand::Operand(std::string s, eOperandType t) : value(s), type(t)
{}

Operand::Operand(const Operand &obj)
{
	type = obj.type;
	value = obj.value;
}
Operand::~Operand()
{}

int Operand::getPrecision() const
{ return type; }

eOperandType Operand::getType() const
{ return type; }

IOperand const* Operand::operator+(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) + std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

IOperand const* Operand::operator-(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) - std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

IOperand const* Operand::operator*(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) * std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

IOperand const* Operand::operator/(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) / std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

IOperand const* Operand::operator%(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stoi(value) % std::stoi(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

std::string const& Operand::toString() const
{ return (value); }
