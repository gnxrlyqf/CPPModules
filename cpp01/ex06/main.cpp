#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl Harl;
	if (ac != 2)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0);

	Harl.complain(av[1]);
}