#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <limits.h>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>

#define DIGITS "0123456789"

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool	isChar(const std::string &representation);
		static bool	isInteger(const std::string &representation);
		static bool	isFloat(const std::string &representation);
		static bool	isDouble(const std::string &representation);
		static bool	isInfinite(const std::string &representation);

		static void	Char(const std::string &representation);
		static void	Integer(const std::string &representation);
		static void	Float(const std::string &representation);
		static void	Double(const std::string &representation);
		static void	Infinite(const std::string &representation);

	public:
		static void convert(const std::string& literal);
};

#endif
