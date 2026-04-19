#include "RPN.hpp"

int main(int ac, char **av) {
	RPN rpn;

	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	
	try {
		rpn(av[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}
}