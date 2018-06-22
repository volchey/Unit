
#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include <ctime>

FragTrap::FragTrap()
{
	std::cout << "default constructor called" << std::endl;
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 100;
	this->maxEnergy = 100;
	this->level = 1;
	this->meleeDamage = 30;
	this->rangedDamage = 20;
	this->armorDamagereduce = 5;
	this->name = "name";
}

FragTrap::FragTrap(std::string const newName)
{
	std::cout << "Copy constructor called" << std::endl;
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 100;
	this->maxEnergy = 100;
	this->level = 1;
	this->meleeDamage = 30;
	this->rangedDamage = 20;
	this->armorDamagereduce = 5;
	this->name = newName;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	FragTrap::funnyAttack(std::string const & target)
{
	std::cout << "<" << this->name << "> "
	<< "attacks <" << target << "> "
	<< "with fun, causing <" << this->meleeDamage
	<< "> points of damage !" << std::endl;
}

void	FragTrap::explosiveAttack(std::string const & target)
{
	std::cout << "<" << this->name << "> "
	<< "attacks <" << target << "> "
	<< "exolosivly, causing <" << this->meleeDamage + 10
	<< "> points of damage !" << std::endl;
}

void	FragTrap::atomAttack(std::string const & target)
{
	std::cout << "<" << this->name << "> "
	<< "attacks <" << target << "> "
	<< "nuclear weapon, causing <" << this->meleeDamage + 100
	<< "> points of damage !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy > 25)
	{
		std::cout << "25 energy used to make a random attack" << std::endl;
		typedef void (FragTrap::*Attack)(std::string const & target);
		Attack functs[5] = {&FragTrap::meleeAttack, &FragTrap::rangedAttack,
			&FragTrap::funnyAttack, &FragTrap::explosiveAttack,
			&FragTrap::atomAttack};
		this->energy -= 25;
		(this->*(functs[rand() % 5]))(target);
	}
	else
	{
		displayEnergyLevel();
		std::cout << "You don't have enough energy to make a random atack." << std::endl;
	}
}