#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) this->stack = other.stack;
	return *this;
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

long op(long a, long b, char op) {
	long res;
	if (op == '+') res = a + b;
	else if (op == '-') res = a - b;
	else if (op == '*') res = a * b;
	else {
		if (b == 0) throw std::runtime_error("Error\n");
		res = a / b;
	}
	if (res > INT_MAX || res < INT_MIN)
		throw std::runtime_error("Error\n");
	return (res);
}

void RPN::operator()(std::string input) {
	input = strtrim(input);
	if (input.empty())
		throw std::runtime_error("");

	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (std::isspace(c))
			continue ;
		else if (std::isdigit(c)) {
			if (i + 1 < input.size() && std::isdigit(input[i + 1]))
				throw std::runtime_error("Error\n");
			stack.push(c - '0');
		} else if (c == '-' || c == '+' || c == '/' || c == '*') {
			if (stack.size() < 2)
				throw std::runtime_error("Error\n");
			long b = stack.top();
			stack.pop();
			long a = stack.top();
			stack.pop();
			stack.push(op(a, b, c));
		} else
			throw std::runtime_error("Error\n");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error\n");
	std::cout << stack.top() << std::endl;
}