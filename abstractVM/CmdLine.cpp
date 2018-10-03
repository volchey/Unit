#include <sstream>
#include <iostream>
#include "CmdLine.hpp"

CmdLine::CmdLine(const std::string &new_line) : _cmdFunc(NULL)
{
    std::stringstream	line(new_line);
    line >> _cmdStr >> _argument;
}

CmdLine::CmdLine(const CmdLine &obj)
{
	_argument = obj._argument;
	_cmdStr = obj._cmdStr;
	_cmdFunc = obj._cmdFunc;
}

CmdLine::~CmdLine()
{}

void 		CmdLine::validate(std::map<std::string, func_t> &func_map) throw(std::exception)
{
	if (_cmdStr.compare(";") && !_cmdStr.empty())
	{
		if (!func_map.count(_cmdStr))
			throw BadCommandException();
		_cmdFunc = func_map[_cmdStr];
	}
}

void CmdLine::call()
{
	if (_cmdFunc)
		_cmdFunc(_argument);
}

std::string	CmdLine::getCmdStr() const
{ return (_cmdStr); }

CmdLine& 	CmdLine::operator=(const CmdLine &obj)
{
	_argument = obj._argument;
	_cmdStr = obj._cmdStr;
	_cmdFunc = obj._cmdFunc;
	return (*this);
}
