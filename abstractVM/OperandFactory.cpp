#include <vector>
#include <cfloat>
#include "OperandFactory.hpp"
#include "Operand.hpp"

OperandFactory::OperandFactory()
{}

OperandFactory::OperandFactory(const OperandFactory &obj)
{}

OperandFactory::~OperandFactory()
{}

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
	double d = stod(value);

	if (d > INT8_MAX || d < INT8_MIN)
		throw Overflow(value, "Int8");
	return (new Operand(value, Int8));
}

IOperand const* OperandFactory::createInt16(std::string const &value) const
{
	double d = stod(value);

	if (d > INT16_MAX || d < INT16_MIN)
		throw Overflow(value, "Int16");
	return (new Operand(value, Int16));
}

IOperand const* OperandFactory::createInt32(std::string const &value) const
{
	double d = stod(value);

	if (d > INT32_MAX || d < INT32_MIN)
		throw Overflow(value, "Int32");
	return (new Operand(value, Int32));
}

IOperand const* OperandFactory::createFloat(std::string const &value) const
{
	double d = stod(value);

	if (d > FLT_MAX || d < FLT_MIN)
		throw Overflow(value, "Float");
	return (new Operand(value, Float));
}

IOperand const* OperandFactory::createDouble(std::string const &value) const
{
	double d = stod(value);

	if (d > DBL_MAX || d < DBL_MIN)
		throw Overflow(value, "Double" );
	return (new Operand(value, Double));
}
