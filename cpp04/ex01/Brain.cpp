#include "Brain.hpp"

Brain::Brain() {
	 << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	 << "Brain Copy Constructor" << std::endl;

}

Brain &Brain::operator=(const Brain &other) {
	int i = -1;
	if (this != &other)
		while (++i < 100)
			ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain() {
	 << "Brain Destructor" << std::endl;
}
