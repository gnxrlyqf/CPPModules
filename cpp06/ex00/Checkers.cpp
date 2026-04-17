#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(const std::string &literal) {
	return (literal.size() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInteger(const std::string &literal) {
    if (literal.empty())
        return (false);
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start++;
    if (start == literal.size() || literal.find_first_not_of(DIGITS, start) != std::string::npos)
        return (false);
    return (true);
}

bool ScalarConverter::isFloat(const std::string &literal) {
	const size_t signal = literal.find('-');
	if (signal != 0 && signal != std::string::npos)
		return (false);

	const size_t dot = literal.find('.');
	if (dot == std::string::npos)
		return (false);

	if (literal[literal.size() - 1] != 'f')
		return (false);

	const std::string dec = literal.substr((signal == 0), dot - (signal == 0));
	const std::string fract = literal.substr(dot + 1, literal.size() - (dot + 1) - 1);

	if (dec.find_first_not_of(DIGITS) != std::string::npos ||
			fract.find_first_not_of(DIGITS) != std::string::npos)
		return (false);

	return (!dec.empty() && !fract.empty());
}

bool ScalarConverter::isDouble(const std::string &literal) {
	const size_t signal = literal.find('-');
	if (signal != 0 && signal != std::string::npos)
		return (false);

	const size_t dot = literal.find('.');
	if (dot == std::string::npos)
		return (false);

	const std::string dec = literal.substr((signal == 0), dot - (signal == 0));
	const std::string fract = literal.substr(dot + 1, literal.size() - dot - 1);

	if (dec.find_first_not_of(DIGITS) != std::string::npos ||
			fract.find_first_not_of(DIGITS) != std::string::npos)
		return (false);

	return (!dec.empty() && !fract.empty());
}

bool ScalarConverter::isInfinite(const std::string &literal) {
	if (literal == "-inff" || literal == "+inf" ||
			literal == "+inff" || literal == "-inf" ||
			literal == "nanf" || literal == "nan")
		return (true);
	return (false);
}
