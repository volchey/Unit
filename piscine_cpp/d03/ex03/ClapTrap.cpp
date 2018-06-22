
#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <ctime>

ClapTrap::ClapTrap()
{
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 50;
	this->maxEnergy = 50;
	this->level = 1;
	this->meleeDamage = 20;
	this->rangedDamage = 15;
	this->armorDamagereduce = 3;
	this->name = "name";
	std::cout << "Parent class constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const newName)
{
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 50;
	this->maxEnergy = 50;
	this->level = 1;
	this->meleeDamage = 20;
	this->rangedDamage = 15;
	this->armorDamagereduce = 3;
	this->name = newName;
	std::cout << "Parent class constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Parent died" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &object)
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

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (this->energy >= 10)
	{
		std::cout << "<" << this->name << "> "
		<< "attacks <" << target << "> "
		<< "at range, causing <" << this->rangedDamage
		<< "> points of damage ! 10 energy points used." << std::endl;
		this->energy -= 10;
	}
	else
		std::cout << "You don't have enough energy to make a range attack." << std::endl;
	displayEnergyLevel();
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (this->energy >= 5)
	{
		std::cout << "<" << this->name << "> "
		<< "attacks <" << target << "> "
		<< "at middle, causing <" << this->meleeDamage
		<< "> points of damage ! 5 energy points used." << std::endl;
		this->energy -= 5;
	}
	else
		std::cout << "You don't have enough energy to make a meddle atack." << std::endl;
	displayEnergyLevel();
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

void	ClapTrap::displayHealthLevel()
{
	if (this->health > 0)
	{
		std::cout << this->health
		<< " health left." << std::endl;
	}
	else
		std::cout << "DEAD" << std::endl;
}

void	ClapTrap::displayEnergyLevel()
{
	std::cout << this->energy
	<< " energy points left." << std::endl;
}
