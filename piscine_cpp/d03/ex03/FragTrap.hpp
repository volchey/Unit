
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string const newName);

	FragTrap	&operator=(ClapTrap const &object);

	void	funnyAttack(std::string const & target);
	void	explosiveAttack(std::string const & target);
	void	atomAttack(std::string const & target);

	void	vaulthunter_dot_exe(std::string const & target);

};

#endif