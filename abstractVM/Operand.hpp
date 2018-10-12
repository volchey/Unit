#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

//template <class T>
class Operand : public IOperand
{
public:
	Operand();
	Operand(std::string, eOperandType);
	Operand(const Operand &);
	~Operand( void );

	int getPrecision( void ) const;
	eOperandType getType( void ) const;
	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;
	std::string const & toString( void ) const;

//	Operand & operator=( Operand const & rhs );
private:
	eOperandType	type;
	std::string		value;
	OperandFactory	factory;
};

#endif