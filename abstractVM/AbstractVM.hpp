
#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <list>
#include <map>
#include "IOperand.hpp"
#include "stdlib.h"
#include "OperandFactory.hpp"

typedef std::function<void(std::string)> func_t;

class AbstractVM
{
public:
	AbstractVM();
    AbstractVM(const AbstractVM &obj);
	~AbstractVM();

	std::list<IOperand *>			getStack() const;
	std::map<std::string, func_t >	getFunc() const;
	static void	                    push(std::string str);
	static void						pop(std::string str);
	static void	                    dump(std::string str);
	static void	                    assert(std::string str);
	static void	                    add(std::string str);
	static void	                    sub(std::string str);
	static void					    mul(std::string str);
	static void	            		div(std::string str);
	static void	                    mod(std::string str);
	static void					    print(std::string str);
	static void	            		exit(std::string str);

    AbstractVM &operator=(AbstractVM const & obj );

private:
	std::list<IOperand *>			stack;
	std::map<std::string, func_t>	functions;
//	OperandFactory					factory;

};

#endif
