#include "Zombie.hpp"

class Zombie {
	private:
		std::string name;

	public:
		void announce(void) {
			std::cout << this->name << ": >: BraiiiiiiinnnzzzZ...\n";
		}
};
