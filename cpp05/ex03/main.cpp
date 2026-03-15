#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidnetialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern i;

	try {
		AForm *f = i.makeForm("shrubberyCreation", "lhrba");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		AForm *f = i.makeForm("robotomyRequest", "lhrba");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "====================================================" << std::endl;
	try {
		AForm *f = i.makeForm("presidentialPardon", "lhrba");
		Bureaucrat b(1, "lbiro9rat");

		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}