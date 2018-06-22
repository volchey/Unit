
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

FragTrap	&FragTrap::operator=(FragTrap const &object)
{
	this->health = object.health;
	this->maxHealth = object.maxHealth;
	this->energy = object.energy;
	this->maxEnergy = object.maxEnergy;
	this->level = object.level;
	this->meleeDamage = object.meleeDamage;
	this->rangedDamage = object.rangedDamage;
	this->armorDamagereduce = object.armorDamagereduce;
	this->name = object.name;
	return (*this);
}


void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->name << "> "
	<< "attacks <" << target << "> "
	<< "at range, causing <" << this->rangedDamage
	<< "> points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "<" << this->name << "> "
	<< "attacks <" << target << "> "
	<< "at middle, causing <" << this->meleeDamage
	<< "> points of damage !" << std::endl;
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

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "<" << this->name << "> "
	<< "take <" << amount << "> damage. Shield block <"
	<< this->armorDamagereduce << "> of damage. ";
	if (amount > this->armorDamagereduce)
	{
		if (this->health < (amount - this->armorDamagereduce))
			this->health = 0;
		else
			this->health -= (amount - this->armorDamagereduce);
	}
	this->displayHealthLevel();
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "<" << this->name << "> "
	<< "restore <" << amount << "> "
	<< "health. ";
	if (this->maxHealth > this->health + amount)
		this->health += amount;
	else
		this->health = this->maxHealth;
	displayHealthLevel();
}

void	FragTrap::displayHealthLevel()
{
	if (this->health > 0)
	{
		std::cout << this->health
		<< " health left." << std::endl;
	}
	else
		std::cout << "DEAD" << std::endl;
}

void	FragTrap::displayEnergyLevel()
{
	std::cout << this->energy
	<< " energy points left." << std::endl;
}
