#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Form f("lhrbation", 151, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f("lhrbation", 0, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b(50, "jamal");
		Form f("lhrbation", 70, 1);

		b.signForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b(80, "jamal");
		Form f("lhrbation", 70, 1);

		b.signForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b(80, "jamal");
		Form f("lhrbation", 70, 1);

		f.beSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}