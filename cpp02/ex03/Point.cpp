#include <iostream>
#include <cmath>
#include "Point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {

}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {
	
}

Point &Point::operator=(const Point &other) {
	(void)other;
	return (*this);
}

Point::~Point() {
	
}

Fixed Point::getX() const {
	return (this->x);
}

Fixed Point::getY() const {
	return (this->y);
}

Fixed Point::area(const Point a, const Point b, const Point c) {
	return (((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y))) / 2);
}

bool Point::bsp(const Point a, const Point b, const Point c, const Point p) {
	float abc = abs(area(a, b, c).toFloat());
	float pab = abs(area(p, a, b).toFloat());
	float pbc = abs(area(p, b, c).toFloat());
	float pac = abs(area(p, a, c).toFloat());

	std::cout << abc << std::endl;
	std::cout << pab + pbc + pac << std::endl;
	return (abc == pab + pbc + pac);
}