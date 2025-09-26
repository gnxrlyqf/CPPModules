#include <iostream>
#include "ScavTrap.hpp"

int main() {
	ScavTrap james("james");

	james.setDamage(1);

	james.attack("lisa");
	james.takeDamage(9);
	james.attack("lisa");
	james.beRepaired(4);
	james.GuardGate();
}