
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

NinjaTrap::NinjaTrap()
{
	std::cout << "A boy become a ninja" << std::endl;
	this->health = 60;
	this->maxHealth = 60;
	this->energy = 120;
	this->maxEnergy = 120;
	this->level = 1;
	this->meleeDamage = 60;
	this->rangedDamage = 5;
	this->armorDamagereduce = 0;
	this->name = "name";
}

NinjaTrap::NinjaTrap(std::string const newName)
{
	std::cout << "A boy become a ninja" << std::endl;
	this->health = 60;
	this->maxHealth = 60;
	this->energy = 120;
	this->maxEnergy = 120;
	this->level = 1;
	this->meleeDamage = 60;
	this->rangedDamage = 5;
	this->armorDamagereduce = 0;
	this->name = newName;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "But... ninja can't die" << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &object)
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

void	NinjaTrap::ninjaShoebox(NinjaTrap const &object)
{
	std::cout << "ninja love another ninja" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const &object)
{
	std::cout << "ninja is afraid of ScavTrap" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const &object)
{
	std::cout << "ninja killed FragTrap" << std::endl;
}
