#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &representation) {
	static bool (*Checkers[])(const std::string &s) = {
		&ScalarConverter::isChar,
		&ScalarConverter::isInteger,
		&ScalarConverter::isFloat,
		&ScalarConverter::isDouble,
		&ScalarConverter::isInfinite
	};

	static void (*converters[])(const std::string &S) = {
		&ScalarConverter::Char,
		&ScalarConverter::Integer,
		&ScalarConverter::Float,
		&ScalarConverter::Double,
		&ScalarConverter::Infinite
	};
	for (int i = 0; i < 5; i++)
		if (Checkers[i](representation))
			return (converters[i](representation));

	std::cout << "Invalid input" << std::endl;
}
