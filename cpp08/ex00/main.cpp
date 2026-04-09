#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "Vector test\n";
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try {
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(vec, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "List test\n";
	std::list<char> ls;

	char a = 'a';
	for (int i = 0; i < 28; i++)
		ls.push_back(a++);
	try {
		std::cout << *easyfind(ls, 'z') << std::endl;
		std::cout << *easyfind(ls, 1000) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "Deque test\n";
	std::deque<int> deq;

	for (int i = 0; i < 350; i++)
		deq.push_back(i);
	try {
		std::cout << *easyfind(deq, 349) << std::endl;
		std::cout << *easyfind(deq, 560) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}