#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat b(151, "lbiro9rat");
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		Bureaucrat b(0, "lbiro9rat");
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		Bureaucrat b(1, "lbiro9rat");
		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		Bureaucrat b(150, "lbiro9rat");
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
}