#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {

}

Fixed::~Fixed() {

}

Fixed::Fixed(const Fixed &other) {
	this->value = other.value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.value = this->value + other.value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.value = this->value - other.value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long val;
	val = (this->value * other.value) >> this->fractionalBits;
	result.value = (int)val;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.getRawBits() == 0)
		return (Fixed(0));
	Fixed result;
	long tmp = ((long)this->value << this->fractionalBits) / other.value;
	result.value = (int)tmp;
	return result;
}

Fixed &Fixed::operator++() {
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--() {
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value--;
	return (temp);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.value);
}

const Fixed &Fixed::min(const Fixed &l, const Fixed &r) {
	return (l < r ? l : r);
}

const Fixed &Fixed::max(const Fixed &l, const Fixed &r) {
	return (l > r ? l : r);
}

Fixed &Fixed::min(Fixed &l, Fixed &r) {
	return (l < r ? l : r);
}

Fixed &Fixed::max(Fixed &l, Fixed &r) {
	return (l > r ? l : r);
}

int Fixed::getRawBits() const {
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
