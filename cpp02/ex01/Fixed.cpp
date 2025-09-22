#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	this->value = other.value;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}