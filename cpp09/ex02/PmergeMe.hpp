#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

#define DIGITS "0987654321"

template <typename T>
class PmergeMe {
	T con;
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		PmergeMe(char **av);
	
		typedef typename T::iterator iter;
		typedef typename std::vector<iter>::iterator iiter;

		const T& getContainer() const { return con; }
		long jacobsthal(long n);
		void swap(iter it1, iter it2);
		iter jump(iter it, int steps);
		iiter jump(iiter it, int steps);
		T insert(std::vector<iter> &pend, std::vector<iter> &main, int depth, bool is_odd);
		void merge(int depth);
		double operator()();

		static bool compare(iter it1, iter it2) { return (*it1 < *it2); }

	class Error : public std::exception {
		public: const char *what() const throw() { return ("Error"); }
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const PmergeMe<T>& obj) {
	const T& cont = obj.getContainer();
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it) {
		if (it != cont.begin())
			os << " ";
		os << *it;
	}
	return os;
}

#endif
