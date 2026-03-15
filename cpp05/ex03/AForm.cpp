#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
	name(""),
	isSigned(false),
	gradeToSign(150),
	gradeToExecute(150) {}

AForm::AForm(std::string n, int sGrade, int eGrade) : name(n), isSigned(false), gradeToSign(sGrade), gradeToExecute(eGrade) {
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

std::string AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > gradeToExecute)
		throw (GradeTooLowException());
	action();
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign)
		throw (GradeTooLowException());
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("form grade is too low");
}

AForm::~AForm() {}