#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string secret;
		Contact();
		Contact(std::string fN, std::string lN, std::string nn, std::string n, std::string s);
};

#endif