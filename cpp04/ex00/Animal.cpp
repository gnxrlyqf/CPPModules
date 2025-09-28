#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Def Constr" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal Copy Constr" << std::endl;

}

Animal& Animal::operator=(const Animal& other) {
	this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}