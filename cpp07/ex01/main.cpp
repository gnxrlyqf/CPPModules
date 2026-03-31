#include "iter.hpp"
#include <math.h>
#include <iostream>

void sq(int x) {
	std::cout << pow(x, 2) << std::endl;
}

void trim(std::string str) {
	std::cout << str.substr(3, 5) << std::endl;
}

int main() {
	{
		int arr[] = {1, 2, 3, 4, 5};

		iter(arr, 5, sq);
	}
	std::cout << "======================================" << std::endl;
	{
		std::string arr[] = {"---test1---", "===test2===", "___test3___", "+++test4+++", "...test5..."};

		iter(arr, 5, trim);
	}
}