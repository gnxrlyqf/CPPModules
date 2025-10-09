#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	 << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
     << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
        this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	 << "WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
	 << "Wrong generic sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
