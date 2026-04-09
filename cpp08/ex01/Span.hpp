#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private:
		unsigned int max_size;
		std::vector<int> arr;
		int min;
		int max;

	public:
		Span();
		Span(const Span & other);
		Span& operator=(const Span & other);
		~Span();
		
		Span(unsigned int N);

		void	addNumber(int num);
		int		longestSpan() const;
		int		shortestSpan() const;

		template <typename T>
		void addNumbers(T begin, T end);
};


#endif