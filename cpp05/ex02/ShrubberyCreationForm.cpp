#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
	return target;
}

void ShrubberyCreationForm::action() const {
	std::ofstream file((target + "_shrubbery").c_str());

	if (!file)
		throw std::runtime_error("File creation failed.");
	file << "  .-'- -.\n"
		<< " (       )\n"
		<< "(  ,      )\n"
		<< "( \'./  .'\n"
		<< "'-| |-'\n"
		<< "    | |\n"
		<< ",,,,|.|,,,\n";
}