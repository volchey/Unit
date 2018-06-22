
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

class FragTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string const newName);
	
	FragTrap	&operator=(FragTrap const &object);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	funnyAttack(std::string const & target);
	void	explosiveAttack(std::string const & target);
	void	atomAttack(std::string const & target);

	void	vaulthunter_dot_exe(std::string const & target);
	
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