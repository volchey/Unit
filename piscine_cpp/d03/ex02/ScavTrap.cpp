
#include "ScavTrap.hpp"
#include <iostream>
#include <string>
#include <ctime>

ScavTrap::ScavTrap()
{
	std::cout << "CrapTrap came in" << std::endl;
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 50;
	this->maxEnergy = 50;
	this->level = 1;
	this->meleeDamage = 20;
	this->rangedDamage = 15;
	this->armorDamagereduce = 3;
	this->name = "name";
}

ScavTrap::ScavTrap(std::string const newName)
{
	std::cout << "CrapTrap came in" << std::endl;
	this->health = 100;
	this->maxHealth = 100;
	this->energy = 50;
	this->maxEnergy = 50;
	this->level = 1;
	this->meleeDamage = 20;
	this->rangedDamage = 15;
	this->armorDamagereduce = 3;
	this->name = newName;
}

ScavTrap::~ScavTrap()
{
	std::cout << "CrapTrap died" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &object)
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

void	ScavTrap::challengeNewcomer()
{
	if (this->energy > 25)
	{
		std::cout << "25 energy used to make a random challenge" << std::endl;
		std::string challenges[5] = {"Kill the enemy",
		"Open a portal to another galaxy", "Surrender",
		"Repaire to full health", "Finish the cpp piscine"};
		this->energy -= 25;
		std::cout << challenges[rand() % 5] << std::endl;
	}
	else
	{
		displayEnergyLevel();
		std::cout << "You don't have enough energy to make a random atack." << std::endl;
	}
}