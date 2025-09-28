#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default Constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}
