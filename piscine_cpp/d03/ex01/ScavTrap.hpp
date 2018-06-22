
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>

class ScavTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string const newName);

	ScavTrap	&operator=(ScavTrap const &object);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);

	void	challengeNewcomer();
	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	displayHealthLevel();
	void	displayEnergyLevel();

private:
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