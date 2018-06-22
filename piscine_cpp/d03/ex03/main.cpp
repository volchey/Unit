#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <ctime>

int main()
{
	srand(time(0));
	FragTrap	frag("vchechai");

	frag.rangedAttack("other trap");
	frag.meleeAttack("other trap");
	frag.takeDamage(20);
	frag.beRepaired(20);
	frag.vaulthunter_dot_exe("target");

	std::cout << std::endl;
	
	ScavTrap	scav("vchechai");

	scav.rangedAttack("other trap");
	scav.meleeAttack("other trap");
	scav.takeDamage(20);
	scav.beRepaired(20);
	scav.challengeNewcomer();

	NinjaTrap	ninja("bob");

	ninja.ninjaShoebox(ninja);
	ninja.ninjaShoebox(scav);
	ninja.ninjaShoebox(frag);

}