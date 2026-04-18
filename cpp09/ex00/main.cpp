#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	(void)av;
	if (ac != 2)
		return (1);

	try {
		BitcoinExchange ex("data.csv");

		ex(std::string(av[1]));
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return (0);
}