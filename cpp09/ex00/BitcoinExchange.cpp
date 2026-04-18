#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>

BitcoinExchange::BitcoinExchange(std::string data) {
	std::ifstream file(data.c_str(), std::ios::in);
	if (!file.is_open())
		throw (bad_db_file());
	
	{
		std::string line;
		
		std::getline(file, line);
		if (line.find(',') == std::string::npos)
			throw (bad_db_file());
		while (std::getline(file, line))
			parseLine(line);
	}
	file.close();
}

void BitcoinExchange::parseLine(std::string &line) {
	size_t comma = line.find(',');
	int key;
	float value;

	if (comma == std::string::npos)
		throw (bad_db_file());

	key = parseDate(line.substr(0, comma));
	value = std::strtof(line.substr(comma + 1).c_str(), NULL);
	setValue(key, value);
}

void BitcoinExchange::setValue(int key, float value) {
	values[key] = value;
}

int BitcoinExchange::parseDate(std::string date) {
	tm time = {};
	time_t unix_time;
	
	{
		size_t delim = date.find('-');

		if (delim == std::string::npos)
			throw (bad_db_file());

		std::string year = date.substr(0, delim);

		if (year.find_first_not_of("0123456789") != std::string::npos)
			throw (bad_db_file());

		time.tm_year = stoi(year) - 1900;
		date = date.substr(delim + 1);
	}
	{
		size_t delim = date.find('-');

		if (delim == std::string::npos)
			throw (bad_db_file());
	
		std::string mon = date.substr(0, delim);
		if (mon.find_first_not_of("0123456789") != std::string::npos)
			throw (bad_db_file());

		time.tm_mon = stoi(mon) - 1;
		date = date.substr(delim + 1);
	}
	{
		if (date == "")
			throw (bad_db_file());
	
		if (date.find_first_not_of("0123456789") != std::string::npos)
			throw (bad_db_file());

		time.tm_mday = stoi(date);
		unix_time = mktime(&time);
	}
	return (static_cast<int>(unix_time));
}

int BitcoinExchange::stoi(std::string str) {
	float f = std::strtof(str.c_str(), NULL);

	return (static_cast<int>(f));
}

std::string	strtrim(const std::string &s) {
	size_t start = 0;
	while (start < s.size() && std::isspace((unsigned char)(s[start])))
		++start;
	size_t end = s.size();
	while (end > start && std::isspace((unsigned char)(s[end - 1])))
		--end;
	return s.substr(start, end - start);
}

void BitcoinExchange::operator()(std::string data) {
	std::ifstream file(data.c_str(), std::ios::in);

	if (!file.is_open())
		throw (bad_input_file());
	{
		std::string line;
		
		std::getline(file, line);
		if (line.find('|') == std::string::npos)
			throw (bad_db_file());
		while (std::getline(file, line))
			try {
				processInput(line);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
	}
}

void BitcoinExchange::processInput(std::string &input) {
	std::string date;
	std::string value;
	std::string out;
	int unix_time;
	float mult;
	size_t delim = input.find('|');

	if (delim == std::string::npos)
		throw (bad_input(input));
	date = strtrim(input.substr(0, delim));
	value = strtrim(input.substr(delim + 1));

	try {
		unix_time = parseDate(date);
	} catch (std::exception &e) {
		throw (bad_input(input));
	}

	while (1) {
		std::map<int, float>::const_iterator it = values.find(unix_time);

		if (it == values.end())
			unix_time -= 86400;
		else
			break;
	}

	if (value.find_first_not_of("-0123456789.") != std::string::npos ||
		value.find_first_of('.') != value.find_last_of('.'))
		throw (bad_input(input));
	mult = std::strtof(value.c_str(), NULL);
	if (mult < 0)
		throw (num_neg());
	if (mult > 1000)
		throw (num_too_large());
	std::cout << date << " => " << value << " = " << (values[unix_time] * mult) << std::endl;
}
