
#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <stack>
#include <map>
#include <list>
#include "stdlib.h"
#include "OperandFactory.hpp"

class AbstractVM
{
public:
	AbstractVM();
    AbstractVM(const AbstractVM &obj);
	~AbstractVM();

	typedef void (AbstractVM::*func_t)(std::string);

	std::list<IOperand const *>			getStack() const;
	std::map<std::string, func_t >	getFunc() const;
	void	                    push(std::string str);
	void						pop(std::string str);
	void	                    dump(std::string str);
	void	                    assert(std::string str);
	void	                    add(std::string str);
	void	                    sub(std::string str);
	void					    mul(std::string str);
	void	            		div(std::string str);
	void	                    mod(std::string str);
	void					    print(std::string str);
	void	            		exit(std::string str);

	class	BadArgumentException : public std::exception
{
	virtual const char *what() const throw()
	{ return ("Invalid argument"); }
};

    AbstractVM &operator=(AbstractVM const & obj );

private:
	std::list<IOperand const *>		stack;
	std::map<std::string, func_t>	functions;
	OperandFactory					factory;
};

#endif
