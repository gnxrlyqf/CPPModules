#include <iostream>

char *amp(char *str)
{
	int i = -1;
	while (*(str + ++i))
		*(str + i) = toupper(*(str + i));
	return (str);
}

int main(int ac, char **av)
{
	int i = 0;

	while (++i < ac)
		std::cout << amp(av[i]);
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
