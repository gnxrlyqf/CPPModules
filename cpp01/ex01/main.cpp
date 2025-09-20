#include "Zombie.hpp"

int main() {
	randomChump("lrhba");
	Zombie *james = newZombie("james");
	james->announce();
	delete james;
}