#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed\n";
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
	this->name = name;
}