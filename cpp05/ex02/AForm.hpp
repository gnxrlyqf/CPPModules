#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm();
		AForm(std::string name, const int sGrade, const int eGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void execute(const Bureaucrat &executor) const;
		virtual void action() const = 0;
		void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

#endif
