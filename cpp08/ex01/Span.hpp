#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

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

		void addNumber(int num);
		int longestSpan() const;
		int shortestSpan() const;

		template <typename T>
		void addNumbers(T begin, T end) {
			long available = max_size - arr.size();

			if (std::distance(begin, end) <= available)
				arr.insert(arr.end(), begin, end);
			else {
				T cut = begin;

				std::advance(cut, available);
				arr.insert(arr.end(), begin, cut);
				throw std::overflow_error("Span overflow: not all numbers were inserted");
			}
		}
};


#endif