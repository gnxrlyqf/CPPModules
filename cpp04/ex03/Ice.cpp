#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &other) : AMateria(other) {
	this->type = other.type;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Ice::~Ice() {
}

const std::string &Ice::getType() const {
	return (this->type);
}

Ice *Ice::Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}
