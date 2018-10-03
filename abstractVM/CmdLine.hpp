#ifndef CMDLINE_HPP
#define CMDLINE_HPP

#include <string>
#include <cstdlib>
#include <map>
#include "AbstractVM.hpp"

class   CmdLine
{
public:
    CmdLine() = default;
	CmdLine(const CmdLine &);
    CmdLine(const std::string &new_line);
    ~CmdLine();

	class	BadCommandException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{ return ("Invalid command"); }
	};

	void			validate(std::map<std::string, func_t> &) throw(std::exception);
	void			call();
    std::string		getCmdStr() const;
	CmdLine &operator=(const CmdLine &);
private:
    std::string	_argument;
	std::string _cmdStr;
	func_t		_cmdFunc;
};

#endif