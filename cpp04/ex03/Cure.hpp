#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
		const std::string &getType() const;
		Cure* clone() const;
		void use(ICharacter &target);
};

#endif