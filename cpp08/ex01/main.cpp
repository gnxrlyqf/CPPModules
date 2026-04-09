#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
	std::srand(std::time(NULL));

	try {
		std::cout << "=== Basic small tests ===" << std::endl;
		Span sp1(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);

		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // expect 2
		std::cout << "Longest span:  " << sp1.longestSpan() << std::endl;  // expect 14

		std::cout << "\n=== Exception tests ===" << std::endl;
		try {
			Span sp2(1);
			sp2.addNumber(42);
			std::cout << sp2.shortestSpan() << std::endl; // should throw
		}
		catch (std::exception &e) {
			std::cout << "Caught exception (shortest): " << e.what() << std::endl;
		}

		try {
			Span sp3(1);
			sp3.addNumber(42);
			std::cout << sp3.longestSpan() << std::endl; // should throw
		} catch (std::exception &e) {
			std::cout << "Caught exception (longest): " << e.what() << std::endl;
		}

		std::cout << "\n=== Massive test with 100000 numbers ===" << std::endl;
		Span big(100000);

		for (int i = 0; i < 100000; i++)
			big.addNumber(std::rand());

		std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << big.longestSpan() << std::endl;

		std::cout << "\n=== Edge test: increasing sequence ===" << std::endl;
		Span seq(100000);
		for (int i = 0; i < 100000; i++)
			seq.addNumber(i);

		std::cout << "Shortest span: " << seq.shortestSpan() << std::endl; // expect 1
		std::cout << "Longest span:  " << seq.longestSpan() << std::endl;  // expect 99999

		std::cout << "\n=== Edge test: identical numbers ===" << std::endl;
		Span dup(1000);
		for (int i = 0; i < 1000; i++)
			dup.addNumber(42);

		std::cout << "Shortest span: " << dup.shortestSpan() << std::endl; // expect 0
		std::cout << "Longest span:  " << dup.longestSpan() << std::endl;  // expect 0

	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
}
