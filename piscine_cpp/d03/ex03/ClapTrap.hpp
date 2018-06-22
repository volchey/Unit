
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include "string"

class ClapTrap
{
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string const newName);

	ClapTrap	&operator=(ClapTrap const &object);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	displayHealthLevel();
	void	displayEnergyLevel();

protected:
	int	health;
	int	maxHealth;
	int	energy;
	int	maxEnergy;
	int	level;
	int	meleeDamage;
	int	rangedDamage;
	int	armorDamagereduce;
	
	std::string	name;

};

#endif