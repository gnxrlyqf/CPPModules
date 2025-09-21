#include "Fixed.hpp"

Fixed::Fixed() : value(0) {

}

Fixed::~Fixed() {

}

Fixed::Fixed(const Fixed &other) {
	this->value = other.value;
}


int Fixed::getRawBits() {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}