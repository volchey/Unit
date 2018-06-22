#include <iostream>
#include "FragTrap.hpp"
#include <ctime>

int main()
{
	srand(time(0));
	FragTrap	trap("vchechai");

	trap.rangedAttack("other trap");
	trap.meleeAttack("other trap");
	trap.takeDamage(20);
	trap.beRepaired(20);
	trap.vaulthunter_dot_exe("target");

	FragTrap	frag("frag");

	trap = frag;
	trap.vaulthunter_dot_exe("target");
}