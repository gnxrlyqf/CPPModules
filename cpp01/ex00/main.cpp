#include "Zombie.hpp"

int main() {
	Zombie *zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;
	std::cout << "=================================\n";
	randomChump("Zombie2");
}