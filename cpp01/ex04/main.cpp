#include <iostream>
#include <fstream>
#include <string>

std::string processInput(int ac, char **av) {
	std::fstream infile;
	std::string string;
	std::string buffer;
	
	if (ac != 4) {
		std::cerr << "Invalid format\n";
		std::cerr << "Usage:\n\t./sed <filename> <expression> <replacement>\n";
		exit(1);
	}
	infile.open(av[1], std::ios::in);
	if (!infile.is_open()) {
		std::cerr << "File opening failed\n";
		exit(2);
	}
	if (!*av[2] || !*av[3]) {
		infile.close();
		std::cerr << "Invalid expression or replacement\n";
		exit(3);
	}
	{
		char c;
		while (infile.get(c))
			string += c;
	}
	return (string);
}

void replaceString(std::string &str, std::string exp, std::string rep) {
	size_t pos;

	while (1) {
		pos = str.find(exp);
		if (pos == std::string::npos)
			break;
		str.erase(pos, exp.size());
		str.insert(pos, rep);
	}
}

int main(int ac, char **av) {
	std::string input;

	input = processInput(ac, av);
	std::ofstream outfile(std::string(av[1]) + ".replace");
	replaceString(input, av[2], av[3]);
	outfile << input;
}