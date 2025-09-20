#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed\n";
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie* newZombie(std::string name) {
	Zombie *zombie = new Zombie(name);

	return (zombie);
}

void randomChump(std::string name) {
	Zombie(name).announce();
}
