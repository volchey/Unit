#ifndef CMDLINE_HPP
#define CMDLINE_HPP

#include <string>
#include <cstdlib>
#include <map>
#include "AbstractVM.hpp"

typedef void (AbstractVM::*func_t)(std::string);

class   CmdLine
{
public:
    CmdLine() = default;
	CmdLine(const CmdLine &);
    CmdLine(const std::string &new_line);
    ~CmdLine();

	void			validate(std::map<std::string, func_t> &) throw(std::exception);
	void			call(AbstractVM &);
    std::string		getCmdStr() const;
	CmdLine &operator=(const CmdLine &);
private:
    std::string	_argument;
	std::string _cmdStr;
	func_t		_cmdFunc;
};

#endif