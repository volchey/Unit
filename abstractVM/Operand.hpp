#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

template <class T>
class Operand : protected IOperand
{
public:
	Operand();
	Operand(T &, std::string &, eOperandType &);
	Operand(const Operand &);
	~Operand() = default;

	int getPrecision();
	eOperandType getType();
	IOperand const * operator+( Operand const & rhs );
	IOperand const * operator-( IOperand const & rhs );
	IOperand const * operator*( IOperand const & rhs );
	IOperand const * operator/( IOperand const & rhs );
	IOperand const * operator%( IOperand const & rhs );
	std::string const & toString();

private:
	T				value;
	eOperandType	type;
	std::string		str;
};

#endif