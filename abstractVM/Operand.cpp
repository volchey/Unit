#include "Operand.hpp"
#include "Exception.hpp"

template <class T> Operand<T>::Operand() :type(Int8), value(nullptr)
{}

template <class T> Operand<T>::Operand(T val, eOperandType t) : type(t)
{
	value = std::to_string(val);
//	auto i = value.size() - 1;

//	while (val != 0 && value[i] == '0')
//	{
//		value.erase(i);
//		--i;
//	}
//	if (value[i] == '.')
//		value.erase(i);
}

template <class T> Operand<T>::Operand(const Operand &obj)
{
	type = obj.type;
	value = obj.value;
	factory = obj.factory;
}
template <class T> Operand<T>::~Operand()
{}

template <class T> int Operand<T>::getPrecision() const
{ return type; }

template <class T> eOperandType Operand<T>::getType() const
{ return type; }

template <class T> IOperand const* Operand<T>::operator+(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) + std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

template <class T> IOperand const* Operand<T>::operator-(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) - std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

template <class T> IOperand const* Operand<T>::operator*(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	std::string		new_value = std::to_string(std::stod(value) * std::stod(rhs.toString()));
	return (factory.createOperand(new_type, new_value));
}

template <class T> IOperand const* Operand<T>::operator/(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	double 			denominator = std::stod(rhs.toString());
	if (denominator == 0)
		throw Exception::DivisionByZero();
	std::string		new_value = std::to_string(std::stod(value) / denominator);
	return (factory.createOperand(new_type, new_value));
}

template <class T> IOperand const* Operand<T>::operator%(IOperand const &rhs) const
{
	eOperandType	new_type = type > rhs.getType() ? type : rhs.getType();
	int 			denominator = std::stoi(rhs.toString());
	if (denominator == 0)
		throw Exception::DivisionByZero();
	std::string		new_value = std::to_string(std::stoi(value) % denominator);
	return (factory.createOperand(new_type, new_value));
}

template <class T> Operand<T>& Operand<T>::operator=(Operand const &rhs)
{
	type = rhs.type;
	value = rhs.value;
	factory = rhs.factory;
	return (*this);
}

template <class T> std::string const& Operand<T>::toString() const
{ return (value); }

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;