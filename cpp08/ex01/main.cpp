#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
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
		} catch (std::exception &e) {
			std::cout << "Caught exception (shortest): " << e.what() << std::endl;
		}

		try {
			Span sp3(1);
			sp3.addNumber(42);
			std::cout << sp3.longestSpan() << std::endl; // should throw
		} catch (std::exception &e) {
			std::cout << "Caught exception (longest): " << e.what() << std::endl;
		}

		std::cout << "\n=== addNumbers test ===" << std::endl;
		Span add(1000);
		std::vector<int> nums;
		for (int i = 0; i < 1000; ++i)
			nums.push_back(i * 2);
		add.addNumbers(nums.begin(), nums.end());
		std::cout << "Shortest span: " << add.shortestSpan() << std::endl; // expect 2
		std::cout << "Longest span:  " << add.longestSpan() << std::endl;  // expect 1998
	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
}
