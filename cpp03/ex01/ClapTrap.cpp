#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hp(10), energy(10), damage(0) {
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : hp(10), energy(10), damage(0) {
	std::cout << "ClapTrap Parametered constructor called\n";
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called\n";
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->damage = other.damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Copy assignment operator called\n";
	if (this != &other) {
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called\n";
}

void ClapTrap::attack(const std::string &target) {
	if (!canDoAction())
		return;
	std::cout << "ClapTrap " << this->name;
	std::cout << " attacks "<< target;
	std::cout << ", causing " << this->damage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!canDoAction())
		return;
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name;
	std::cout << " takes " << amount;
	std::cout << " damage. Current HP: " << this->hp;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!canDoAction())
		return;
	this->hp += amount;
	std::cout << "ClapTrap " << this->name;
	std::cout << " repairs itself for " << amount;
	std::cout << " HP. Current HP: " << this->hp;
	std::cout << std::endl;
}

bool ClapTrap::canDoAction() {
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << " is dead, ";
		std::cout << "cannot perform action\n";
		return (false);
	}
	if (this->energy <= 0) {
		std::cout << "ClapTrap " << this->name << " has no energy, ";
		std::cout << "cannot perform action\n";
		return (false);
	}
	return (true);
}

std::string ClapTrap::getName() const {
	return (this->name);
}

int ClapTrap::getHP() const {
	return (this->hp);
}

int ClapTrap::getDamage() const {
	return (this->damage);
}

int ClapTrap::getEnergy() const {
	return (this->energy);
}

void ClapTrap::setName(const std::string &name) {
	this->name = name;
}

void ClapTrap::setHP(int hp) {
	this->hp = hp;
}

void ClapTrap::setDamage(int damage) {
	this->damage = damage;
}

void ClapTrap::setEnergy(int energy) {
	this->energy = energy;
}