#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	 << "Dog Default Constructor" << std::endl;	
}

Dog::Dog(const Dog &other) : Animal(other) {
	*this = other;
	 << "Dog Copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
        this->type = other.type;
	return *this;
}

Dog::~Dog() {
	 << "Dog Destructor" << std::endl;
}

void	Dog::makeSound() const {
	 << "Woof woof!" << std::endl;
}
