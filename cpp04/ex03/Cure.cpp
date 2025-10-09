#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {

}

Cure::Cure(const Cure &other) : AMateria(other) {
	this->type = other.type;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cure::~Cure() {
}

const std::string &Cure::getType() const {
	return (this->type);
}

Cure *Cure::Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
