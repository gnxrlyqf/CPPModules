#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(const std::string &representation) {
	return (representation.size() == 1 && !std::isdigit(representation[0]));
}

bool ScalarConverter::isInteger(const std::string &representation) {
    if (representation.empty())
        return (false);
    size_t start = 0;
    if (representation[0] == '+' || representation[0] == '-')
        start++;
    if (start == representation.size() || representation.find_first_not_of(DIGITS, start) != std::string::npos)
        return (false);
    return (true);
}

bool ScalarConverter::isFloat(const std::string &representation) {
	const size_t signal = representation.find('-');
	if (signal != 0 && signal != std::string::npos)
		return (false);

	const size_t dot = representation.find('.');
	if (dot == std::string::npos)
		return (false);

	if (representation[representation.size() - 1] != 'f')
		return (false);

	const std::string dec = representation.substr((signal == 0), dot - (signal == 0));
	const std::string fract = representation.substr(dot + 1, representation.size() - (dot + 1) - 1);

	if (dec.find_first_not_of(DIGITS) != std::string::npos ||
			fract.find_first_not_of(DIGITS) != std::string::npos)
		return (false);

	return (!dec.empty() && !fract.empty());
}

bool ScalarConverter::isDouble(const std::string &representation) {
	const size_t signal = representation.find('-');
	if (signal != 0 && signal != std::string::npos)
		return (false);

	const size_t dot = representation.find('.');
	if (dot == std::string::npos)
		return (false);

	const std::string dec = representation.substr((signal == 0), dot - (signal == 0));
	const std::string fract = representation.substr(dot + 1, representation.size() - dot - 1);

	if (dec.find_first_not_of(DIGITS) != std::string::npos ||
			fract.find_first_not_of(DIGITS) != std::string::npos)
		return (false);

	return (!dec.empty() && !fract.empty());
}

bool ScalarConverter::isInfinite(const std::string &representation) {
	if (representation == "-inff" || representation == "+inf" ||
			representation == "+inff" || representation == "-inf" ||
			representation == "nanf" || representation == "nan")
		return (true);
	return (false);
}
