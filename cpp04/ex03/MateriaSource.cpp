#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	this->memory[0] = NULL;
	this->memory[1] = NULL;
	this->memory[2] = NULL;
	this->memory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	this->memory[0] = other.memory[0];
	this->memory[1] = other.memory[1];
	this->memory[2] = other.memory[2];
	this->memory[3] = other.memory[3];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		this->memory[0] = other.memory[0];
		this->memory[1] = other.memory[1];
		this->memory[2] = other.memory[2];
		this->memory[3] = other.memory[3];
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	delete this->memory[0];
	delete this->memory[1];
	delete this->memory[2];
	delete this->memory[3];
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!this->memory[0])
		this->memory[0] = materia;
	else if (!this->memory[1])
		this->memory[1] = materia;
	else if (!this->memory[2])
		this->memory[2] = materia;
	else if (!this->memory[3])
		this->memory[3] = materia;
	else
		std::cout << "Inventory full.\n";
}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] && type == this->memory[i]->getType())
			return (this->memory[i]->clone());
	}
	std::cout << "Unknown materia type\n";
	return (NULL);
}
