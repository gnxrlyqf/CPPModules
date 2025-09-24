#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap andrew("andrew");

	andrew.setDamage(1);

	andrew.attack("mark");
	andrew.takeDamage(9);
	andrew.attack("mark");
	andrew.beRepaired(4);
}