#include <vector>
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
	Operand<int8_t> operand();
}

IOperand const* OperandFactory::createInt16(std::string const &value) const
{}

IOperand const* OperandFactory::createInt32(std::string const &value) const
{}

IOperand const* OperandFactory::createFloat(std::string const &value) const
{}

IOperand const* OperandFactory::createDouble(std::string const &value) const
{}
