#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidnetialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		ShrubberyCreationForm f("lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(f);
		b.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		RobotomyRequestForm f("lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(f);
		b.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		PresidentialPardonForm f("lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(f);
		b.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}