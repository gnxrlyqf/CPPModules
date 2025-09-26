#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called\n";
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Parametered constructor called\n";
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string &target) {
	if (!canDoAction())
		return;
	std::cout << "ScavTrap " << this->name;
	std::cout << " attacks "<< target;
	std::cout << ", causing " << this->damage;
	std::cout << " points of damage!" << std::endl;
}

void ScavTrap::GuardGate() {
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode.\n";
}
