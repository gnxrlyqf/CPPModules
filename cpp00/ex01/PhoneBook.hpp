#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int curr;
		int full;
		void trunc_str(std::string str);
		void print_contact(int index, Contact &contact);
	
	public:
		PhoneBook();
		void add(Contact contact);
		void display();
		void display(int index);
};

#endif
