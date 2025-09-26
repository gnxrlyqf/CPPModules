#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hp;
		unsigned int energy;
		unsigned int damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		std::string getName() const;
		int getHP() const;
		int getDamage() const;
		int getEnergy() const;
		void setName(const std::string &name);
		void setHP(int hp);
		void setDamage(int damage);
		void setEnergy(int energy);
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool canDoAction();
};

#endif
