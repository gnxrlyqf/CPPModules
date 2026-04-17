#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidnetialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern i;

	try {
		AForm *f = i.makeForm("shrubberyCreation", "lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		AForm *f = i.makeForm("robotomyRequest", "lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		AForm *f = i.makeForm("presidentialPardon", "lform");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}