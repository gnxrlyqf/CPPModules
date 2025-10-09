#include "Cat.hpp"

Cat::Cat() {
	 << "Cat Default Constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	 << "Cat Copy Constructor" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	 << "Cat Destructor" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	 << "Meow meow!" << std::endl;
}
