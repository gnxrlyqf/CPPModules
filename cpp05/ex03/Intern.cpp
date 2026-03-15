#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidnetialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string& target) const {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string& target) const {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) const {
	std::string formNames[3] = {
		"shrubberyCreation",
		"robotomyRequest",
		"presidentialPardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cerr << "Intern cannot create form: " << name 
			  << " (unknown type)" << std::endl;
	return NULL;
}
