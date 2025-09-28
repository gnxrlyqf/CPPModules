#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat Def Constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}
