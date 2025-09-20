#include <iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "memory address of the string variable: " << &string << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "memory value of the string variable: " << string << std::endl;
	std::cout << "memory value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "memory value pointed to by stringREF: " << stringREF << std::endl;
}