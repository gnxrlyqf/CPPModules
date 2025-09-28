#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong meow??" << std::endl;
}
