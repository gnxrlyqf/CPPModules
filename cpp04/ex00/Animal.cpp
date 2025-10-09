#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	 << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	 << "Animal Copy Constructor" << std::endl;

}

Animal &Animal::operator=(const Animal &other) {
	this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	 << "Animal Destructor" << std::endl;
}

void Animal::makeSound() const {
	 << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}