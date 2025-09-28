#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal *animals[4];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}