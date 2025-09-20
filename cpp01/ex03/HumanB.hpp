#ifndef __HUMANB_HPP_
#define __HUMANB_HPP_

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif