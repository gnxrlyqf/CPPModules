#ifndef __HUMANA_HPP_
#define __HUMANA_HPP_

#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};

#endif