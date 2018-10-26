#include <vector>
#include <cfloat>
#include <iostream>
#include "OperandFactory.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

IOperand const* OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
	std::vector<IOperand const *(OperandFactory::*)(std::string const &) const > func;

	func = {
			&OperandFactory::createInt8,
			&OperandFactory::createInt16,
			&OperandFactory::createInt32,
			&OperandFactory::createFloat,
			&OperandFactory::createDouble
	};

	return ((this->*func[type])(value));
}

IOperand const* OperandFactory::createInt8(std::string const &value) const
{
	int d;

	try
	{ d = stoi(value); }
	catch (std::exception &e)
	{ throw Exception::Overflow(value, "Int8"); }

	if (d > INT8_MAX || d < INT8_MIN)
		throw Exception::Overflow(value, "Int8");
	int8_t var = static_cast<int8_t>(d);
	return (new Operand<int8_t>(var, Int8));
}

IOperand const* OperandFactory::createInt16(std::string const &value) const
{
	int d;

	try
	{ d = stoi(value); }
	catch (std::exception &e)
	{ throw Exception::Overflow(value, "Int16"); }

	if (d > INT16_MAX || d < INT16_MIN)
		throw Exception::Overflow(value, "Int16");
	int16_t var = static_cast<int16_t>(d);
	return (new Operand<int16_t>(var, Int16));
}

IOperand const* OperandFactory::createInt32(std::string const &value) const
{
	long long d;

	try
	{ d = stoll(value); }
	catch (std::exception &e)
	{ throw Exception::Overflow(value, "Int32"); }

	if (d > INT32_MAX || d < INT32_MIN)
		throw Exception::Overflow(value, "Int32");
	int32_t var = static_cast<int32_t>(d);
	return (new Operand<int32_t>(var, Int32));
}

IOperand const* OperandFactory::createFloat(std::string const &value) const
{
	double d;

	try
	{ d = stod(value); }
	catch (std::exception &e)
	{ throw Exception::Overflow(value, "float"); }

	if (d > FLT_MAX || d < -FLT_MIN)
		throw Exception::Overflow(value, "Float");
	float var = static_cast<float>(d);
	return (new Operand<float>(var, Float));
}

IOperand const* OperandFactory::createDouble(std::string const &value) const
{
	double d;

	try
	{ d = stod(value); }
	catch (std::exception &e)
	{ throw Exception::Overflow(value, "double"); }

	if (d > DBL_MAX || d < -DBL_MIN)
		throw Exception::Overflow(value, "Double" );
	return (new Operand<double>(d, Double));
}
