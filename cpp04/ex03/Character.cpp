#include "Character.hpp"
#include <iostream>

Character::Character() {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(std::string name) : name(name) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const Character &other) {
	this->name = other.name;
	this->inventory[0] = other.inventory[0];
	this->inventory[1] = other.inventory[1];
	this->inventory[2] = other.inventory[2];
	this->inventory[3] = other.inventory[3];
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->name = other.name; 
		this->inventory[0] = other.inventory[0];
		this->inventory[1] = other.inventory[1];
		this->inventory[2] = other.inventory[2];
		this->inventory[3] = other.inventory[3];	
	}
	return (*this);
}

Character::~Character() {
	delete this->inventory[0];
	delete this->inventory[1];
	delete this->inventory[2];
	delete this->inventory[3];
}

const std::string &Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria *m) {
	if (!this->inventory[0])
		this->inventory[0] = m;
	else if (!this->inventory[1])
		this->inventory[1] = m;
	else if (!this->inventory[2])
		this->inventory[2] = m;
	else if (!this->inventory[3])
		this->inventory[3] = m;
	else
		std::cout << "Inventory full.\n";
}

void Character::unequip(int idx) {
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range\n";
		return;
	}
	if (!this->inventory[idx]) {
		std::cout << "There is nothing in that slot\n";
		return;
	}
	this->inventory[idx]->use(target);
}
