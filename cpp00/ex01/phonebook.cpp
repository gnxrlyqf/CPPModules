#include <iostream>
#include <cstring>
#include <vector>

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string secret;

		Contact(std::string fN, std::string lN, std::string nn, std::string n, std::string s) {
			firstName = fN;
			lastName = lN;
			nickname = nn;
			number = n;
			secret = s;
		}
};

class PhoneBook {
	private:
		std::vector<Contact> contacts;
		std::vector<Contact>::iterator oldest;

		void trunc_str(std::string str) {
			if (str.size() > 10)
				std::cout.write(str.c_str(), 9) << ".";
			else
				std::cout.write("          ", 10 - str.size()) << str;
		}
		
		void print_contact(int index, Contact contact) {
			std::cout << "         " << index << "|";
			trunc_str(contact.firstName);
			std::cout << "|";
			trunc_str(contact.lastName);
			std::cout << "|";
			trunc_str(contact.nickname);
			std::cout << std::endl;
		}
	
	public:
		PhoneBook() {
			contacts.reserve(8);
			oldest = contacts.begin();
		}
		
		void add(Contact contact) {
			if (contacts.size() < 8)
				contacts.push_back(contact);
			else {
				*oldest = contact;
				++oldest;
				if (oldest == contacts.end())
					oldest = contacts.begin();
			}
		}

		void display() {
			std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
			std::cout << "----------|----------|----------|----------" << std::endl;
			if (!contacts.size())
				std::cout << "                No contacts                " << std::endl;
			for (int i = 0; i < contacts.size(); i++)
				print_contact(i, contacts[i]);
		}

		void display(int index) {
			if (index < 0 || index + 1 > contacts.size())
			{
				std::cerr << "Error: index out of bounds" << std::endl;
				return;
			}
			std::cout << "First Name: " << contacts[index].firstName << std::endl;
			std::cout << "Last Name: " << contacts[index].lastName << std::endl;
			std::cout << "Number: " << contacts[index].number << std::endl;
			std::cout << "Nickname: " << contacts[index].nickname << std::endl;
			std::cout << "Darkest secret: " << contacts[index].secret << std::endl;
		}
};

int validate_num(const char *str) {
	const char *cpy;

	cpy = str;
	while (*str)
	{
		if (!isdigit(*str))
			return (-1);
		str++;
	}
	return (atoi(cpy));
}

void add(PhoneBook *pb) {
	std::string first = "";
	std::string last = "";
	std::string nick = "";
	std::string secret = "";
	std::string number = "";

	std::cout << "First name: ";
	std::cin >> first;
	if (!std::cin.eof() || !std::cin.fail()) {
		std::cout << "Last name: ";
		std::cin >> last;
	}
	if (!std::cin.eof() || !std::cin.fail()) {
		std::cout << "Nickname: ";
		std::cin >> nick;
	}
	if (!std::cin.eof() || !std::cin.fail()) {
		std::cout << "Number: ";
		std::cin >> number;
	}
	if (!std::cin.eof() || !std::cin.fail()) {
		std::cout << "Darkest secret: ";
		std::getline(std::cin >> std::ws, secret);
	}
	if (std::cin.fail())
		std::cerr << "\nError: Invalid input, aborting." << std::endl;
	else
		pb->add(Contact(first, last, nick, number, secret));
}

void search(PhoneBook *pb) {
	pb->display();
	int num;
	std::string input;

	while (1) {
		std::cout << "Search> ";
		std::cin >> input;
		if (!strcmp(input.c_str(), "exit"))
			break ;
		num = validate_num(input.c_str());
		if (num < 0)
		{
			std::cerr << "Error: Invalid input, try again." << std::endl;
			continue;
		}
		pb->display(num);
	}
}

int main(int ac, char **av) {
	PhoneBook pb;
	std::string input;

	while (1) {
		std::cout << "Phonebook> ";
		std::cin >> input;
		if (std::cin.eof() || std::cin.fail())
			break;
		else if (!strcmp(input.c_str(), "ADD"))
			add(&pb);
		else if (!strcmp(input.c_str(), "SEARCH"))
			search(&pb);
		else if (!strcmp(input.c_str(), "EXIT"))
			break;
		else
			std::cerr << "Error: Unknown command" << std::endl;
	}
}