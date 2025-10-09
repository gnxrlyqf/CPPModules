#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	 << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	*this = other;
	 << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	 << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	 << "Meow meow!" << std::endl;
}
