#include "Harl.hpp"

int main()
{
	Harl harl;

	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	std::cout << "===========================\n";
	{
		std::string sequence[] = {"WARNING", "DEBUG", "ERROR", "INFO", "ERROR", "DEBUG"};
		for (int i = 0; i < 6; ++i)
			harl.complain(sequence[i]);
	}
	std::cout << "===========================\n";
	{
		harl.complain("TRACE");
		harl.complain("CRITICAL");
		harl.complain("");
	}
	return 0;
}