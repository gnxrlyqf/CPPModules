#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		~Zombie();
		void announce();
		void setName(std::string n);
	};

Zombie* zombieHorde(int N, std::string name);

#endif