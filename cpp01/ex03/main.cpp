#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "======================================\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "======================================\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanB mark("Mark");
		mark.attack();
		mark.setWeapon(club);
		mark.attack();
	}
	return 0;
}