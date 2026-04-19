#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
	std::cout << "--- Test default constructor ---\n";
	Array<int> empty;
	std::cout << "Size of empty array: " << empty.size() << "\n";

	std::cout << "\n--- Test parameter constructor ---\n";
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;
		
	std::cout << "Numbers array: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n";

	std::cout << "\n--- Test copy constructor ---\n";
	Array<int> copyNumbers(numbers);
	copyNumbers[0] = 999;
	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\nCopy: ";
	for (unsigned int i = 0; i < copyNumbers.size(); ++i)
		std::cout << copyNumbers[i] << " ";
	std::cout << "\n";

	std::cout << "\n--- Test assignment operator ---\n";
	Array<int> assignArray;
	assignArray = numbers;
	assignArray[1] = 555; // modify assigned copy
	std::cout << "Original: ";
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\nAssigned: ";
	for (unsigned int i = 0; i < assignArray.size(); ++i)
		std::cout << assignArray[i] << " ";
	std::cout << "\n";

	std::cout << "\n--- Test exception on out-of-bounds ---\n";
	try
	{
		numbers[10] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n--- Test Array with strings ---\n";
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "42";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n";

	std::cout << "\n--- Test deep copy for strings ---\n";
	Array<std::string> copyWords(words);
	copyWords[0] = "Hi";
	std::cout << "Original: ";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\nCopy: ";
	for (unsigned int i = 0; i < copyWords.size(); ++i)
		std::cout << copyWords[i] << " ";
	std::cout << "\n";

	return 0;
}