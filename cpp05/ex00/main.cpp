#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	// Bureaucrat grade too low
	try {
		Bureaucrat b(151, "lbiro9rat");
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	// Bureaucrat grade too high
	try {
		Bureaucrat b(0, "lbiro9rat");
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	// Bureaucrat cannot be increased
	try {
		Bureaucrat b(1, "lbiro9rat");
		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	// Bureaucrat cannot be decreased
	try {
		Bureaucrat b(150, "lbiro9rat");
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
}