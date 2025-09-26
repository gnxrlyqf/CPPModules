#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap Default constructor called\n";
	this->hp = FragTrap().getHP();
	this->energy = ScavTrap().getEnergy();
	this->damage = FragTrap().getDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap Parametered constructor called\n";
	this->hp = FragTrap().getHP();
	this->energy = ScavTrap().getEnergy();
	this->damage = FragTrap().getDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
	std::cout << "DiamondTrap Copy constructor called\n";
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called\n";
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << this->name;
	std::cout << "'s ClapTrap name is " << ClapTrap::getName();
}
