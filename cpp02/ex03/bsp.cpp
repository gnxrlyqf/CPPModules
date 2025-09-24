#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Fixed abs(Fixed n) {
	return (n < 0 ? n * -1 : n);
}

Fixed area(const Point a, const Point b, const Point c) {
	return (
		((a.getX() * (b.getY() - c.getY())) +
		(b.getX() * (c.getY() - a.getY())) +
		(c.getX() * (a.getY() - b.getY()))) / 2
	);
}

bool bsp(const Point a, const Point b, const Point c, const Point p) {
	Fixed abc = abs(area(a, b, c));
	Fixed pab = abs(area(p, a, b));
	Fixed pbc = abs(area(p, b, c));
	Fixed pac = abs(area(p, a, c));

	std::cout << abc << std::endl;
	std::cout << pab + pbc + pac << std::endl;
	return (abc == pab + pbc + pac);
}