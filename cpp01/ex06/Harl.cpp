#include "Harl.hpp"

void debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void error() {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
    void (Harl::*func[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4 && (levels[i] != level); i++);
	switch (i)
	{
		case 0:
			(this->*func[0])();
		case 1:
			(this->*func[1])();
		case 2:
			(this->*func[2])();
		case 3:
			(this->*func[3])(); break;
		default:
			std::cout << "Unknown level.\n";
	}
}