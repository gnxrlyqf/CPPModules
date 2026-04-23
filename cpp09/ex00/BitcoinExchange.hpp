#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	std::map<int, float> values;

	void parseLine(std::string &line);
	int parseDate(std::string date);
	void processInput(std::string &input);
	int stoi(std::string str);

	public:
		BitcoinExchange() {};
		BitcoinExchange(std::string data);
		~BitcoinExchange() {};

		void setValue(int key, float value);
		void operator()(std::string input);

	class bad_db_file : public std::exception {
		public: const char* what() const throw() { return "Error: bad database file"; }
	};
	class bad_input_file : public std::exception {
		public: const char* what() const throw() { return "Error: could not open file."; }
	};
	class bad_input : public std::exception {
		std::string e;
		public:
			bad_input(const std::string& msg) : e("Error: bad input => " + msg) {}
			~bad_input() throw() {}
			const char* what() const throw() { return (e.c_str()); }
	};
	class num_too_large : public std::exception {
		public: const char* what() const throw() { return "Error: too large a number."; }
	};
	class num_neg : public std::exception {
		public: const char* what() const throw() { return "Error: not a positive number."; }
	};
};

#endif