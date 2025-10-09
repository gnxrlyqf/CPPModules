#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstring>
#include <vector>

Contact::Contact() : firstName(""), lastName(""), nickname(""), number(""), secret("") {

}

Contact::Contact(std::string fN, std::string lN, std::string nn, std::string n, std::string s) {
	firstName = fN;
	lastName = lN;
	nickname = nn;
	number = n;
	secret = s;
}

void PhoneBook::trunc_str(std::string str) {
	if (str.size() > 10)
		std::cout.write(str.c_str(), 9) << ".";
	else
		std::cout.write("          ", 10 - str.size()) << str;
}

void PhoneBook::print_contact(int index, Contact &contact) {
	std::cout << "         " << index << "|";
	trunc_str(contact.firstName);
	std::cout << "|";
	trunc_str(contact.lastName);
	std::cout << "|";
	trunc_str(contact.nickname);
	std::cout << std::endl;
}
	
PhoneBook::PhoneBook() : curr(0), full(0) {

}
		
void PhoneBook::add(Contact contact) {
		contacts[curr++] = contact;
		if (full < 8)
			full++;
		if (curr == 8)
			curr = 0;
}

void PhoneBook::display() {
	std::cout << "     Index|First Name| Last Name|  Nickname\n";
	std::cout << "----------|----------|----------|----------\n";
	if (!full)
		std::cout << "                No contacts                \n";
	for (int i = 0; i < full; i++)
		print_contact(i, contacts[i]);
}

void PhoneBook::display(int index) {
	if (index < 0 || index + 1 > full)
	{
		std::cerr << "Error: index out of bounds\n";
		return;
	}
	std::cout << "First Name: " << contacts[index].firstName << std::endl;
	std::cout << "Last Name: " << contacts[index].lastName << std::endl;
	std::cout << "Number: " << contacts[index].number << std::endl;
	std::cout << "Nickname: " << contacts[index].nickname << std::endl;
	std::cout << "Darkest secret: " << contacts[index].secret << std::endl;
}

void trim(std::string &s)
{
	size_t start = 0;
	while (start < s.size() && std::isspace((unsigned char)(s[start])))
		++start;
	size_t end = s.size();
	while (end > start && std::isspace((unsigned char)(s[end - 1])))
		--end;
	s = s.substr(start, end - start);
}

int validate_num(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (-1);
	}
	return (atoi(str.c_str()));
}

void add(PhoneBook *pb) {
	std::string first = "";
	std::string last = "";
	std::string nick = "";
	std::string secret = "";
	std::string number = "";

	std::cout << "First name: ";
	std::getline(std::cin, first);
	trim(first);
	if (!first.empty() && (!std::cin.eof() || !std::cin.fail())) {
		std::cout << "Last name: ";
		std::getline(std::cin, last);
		trim(last);
	}
	if (!last.empty() && (!std::cin.eof() || !std::cin.fail())) {
		std::cout << "Nickname: ";
		std::getline(std::cin, nick);
		trim(nick);
	}
	if (!nick.empty() && (!std::cin.eof() || !std::cin.fail())) {
		std::cout << "Number: ";
		std::getline(std::cin, number);
		trim(number);
	}
	if (!number.empty() && (validate_num(number) != -1 && (!std::cin.eof() || !std::cin.fail()))) {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, secret);
		trim(secret);
	}
	if (std::cin.eof() || secret.empty())
		std::cerr << "Error: Invalid input, aborting.\n";
	else
		pb->add(Contact(first, last, nick, number, secret));
}

void search(PhoneBook *pb) {
	pb->display();
	int num;
	std::string input;

	std::cout << "Search> ";
	std::getline(std::cin, input);
	num = validate_num(input);
	if (num < 0) {
		std::cerr << "Error: Invalid input, try again." << std::endl;
		return;
	}
	pb->display(num);
}

int main(int ac, char **av) {
	PhoneBook pb;
	std::string input;

	while (1) {
		std::cout << "Phonebook> ";
		std::getline(std::cin, input);
		trim(input);
		if (std::cin.eof() || std::cin.fail())
			break;
		if (input.empty())
			continue;
		else if (!input.compare("ADD"))
			add(&pb);
		else if (!input.compare("SEARCH"))
			search(&pb);
		else if (!input.compare("EXIT"))
			break;
		else
			std::cerr << "Error: Unknown command" << std::endl;
	}
}
