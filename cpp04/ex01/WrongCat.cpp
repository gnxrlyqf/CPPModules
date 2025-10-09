#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	 << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	*this = other;
	 << "WrongCat Copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	 << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	 << "Wrong meow??" << std::endl;
}
