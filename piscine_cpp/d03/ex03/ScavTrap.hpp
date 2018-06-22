
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string const newName);

	ScavTrap	&operator=(ScavTrap const &object);

	void	challengeNewcomer();

};

#endif