#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	name(""),
	isSigned(false),
	gradeToSign(150),
	gradeToExecute(150) {}

Form::Form(std::string n, int sGrade, int eGrade) : name(n), isSigned(false), gradeToSign(sGrade), gradeToExecute(eGrade) {
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

std::string Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign)
		throw (GradeTooLowException());
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("form grade is too low");
}

Form::~Form() {}