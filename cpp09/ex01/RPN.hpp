#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <climits>

class RPN {
	private:
		std::stack<long> stack;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void operator()(std::string input);
};

#endif