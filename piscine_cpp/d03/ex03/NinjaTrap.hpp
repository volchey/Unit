
#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string newName);
	~NinjaTrap();

	NinjaTrap	&operator=(NinjaTrap const &object);

	void	ninjaShoebox(NinjaTrap const &object);
	void	ninjaShoebox(ScavTrap const &object);
	void	ninjaShoebox(FragTrap const &object);
};

#endif