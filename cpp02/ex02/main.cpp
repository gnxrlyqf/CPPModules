#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a(6.1f);
	Fixed b(3.2f);
	Fixed c = a - b;

	std::cout << c << std::endl;
	return 0;
}