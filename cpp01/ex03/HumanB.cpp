#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(0) {
	this->name = name;
}

void HumanB::attack() {
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their fists\n";
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}