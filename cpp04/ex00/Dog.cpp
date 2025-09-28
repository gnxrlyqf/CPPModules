#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog Default Constructor" << std::endl;	
}

Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
        this->type = other.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}
