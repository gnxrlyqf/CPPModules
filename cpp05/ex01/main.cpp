#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	// Form grade too low
	try {
		Form f("lhrbation", 151, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// Form grade too high
	try {
		Form f("lhrbation", 0, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// Bureaucrat can sign form
	try {
		Bureaucrat b(50, "lbiro9rat");
		Form f("lhrbation", 70, 1);

		b.signForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// Bureaucrat cannot sign form
	try {
		Bureaucrat b(80, "lbiro9rat");
		Form f("lform", 70, 1);

		b.signForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// Form cannot be signed
	try {
		Bureaucrat b(80, "lbiro9rat");
		Form f("lform", 70, 1);

		f.beSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}