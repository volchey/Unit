#include "Operand.hpp"

template <class T> Operand<T>::Operand() : value(0), str(0), type(Int8)
{}

template <class T> Operand<T>::Operand(T &v, std::string &s, eOperandType &t):
value(v), str(s), type(t)
{}

template <class T> Operand<T>::Operand(const Operand &obj)
{
	value = obj.value;
	type = obj.type;
	str = obj.str;
}

template <class T> int Operand<T>::getPrecision()
{}

template <class T> eOperandType Operand<T>::getType()
{ return type; }

template <class T> IOperand const* Operand<T>::operator+(Operand const &rhs)
{ return (value + rhs.value); }

template <class T> IOperand const* Operand<T>::operator-(IOperand const &rhs)
{}

template <class T> IOperand const* Operand<T>::operator*(IOperand const &rhs)
{}

template <class T> IOperand const* Operand<T>::operator/(IOperand const &rhs)
{}

template <class T> IOperand const* Operand<T>::operator%(IOperand const &rhs)
{}

template <class T> std::string const& Operand<T>::toString()
{}
