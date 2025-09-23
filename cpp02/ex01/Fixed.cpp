#include <iostream>
#include <cmath>
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

Fixed::Fixed(const int n) {
	this->value = n << this->fractionalBits;
}

Fixed::Fixed(const float n) {
	this->value = roundf(n * (1 << this->fractionalBits));
}

int Fixed::toInt() const {
	return (this->value >> fractionalBits);
}

float Fixed::toFloat() const {
	return (float(this->value) / (1 << this->fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}