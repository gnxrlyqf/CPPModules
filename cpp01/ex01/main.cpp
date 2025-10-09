#include "Zombie.hpp"

int main() {
	Zombie *horde = zombieHorde(5, "Zombie");
	std::cout << "=================================\n";
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	std::cout << "=================================\n";
	delete[] horde;
}