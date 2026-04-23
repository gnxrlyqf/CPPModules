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

// Implementation
template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other) : con(other.con) {}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& other) {
	if (this != &other) {
		con = other.con;
	}
	return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(char **av) {
	while (*av) {
		std::string arg(*av);

		if (arg.find_first_not_of(DIGITS) != std::string::npos)
			throw (Error());
		std::istringstream iss(arg);
		int value;

		iss >> value;
		if (iss.fail() || std::find(con.begin(), con.end(), value) != con.end())
			throw (Error());
		con.push_back(value);
		av++;
	}
};

template <typename T>
long PmergeMe<T>::jacobsthal(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

template <typename T>
void PmergeMe<T>::swap(iter it1, iter it2) {
	iter stop = it1;
	while (stop != it2) {
		std::iter_swap(it1, it2);
		--it1;
		--it2;
	}
}

template <typename T>
typename PmergeMe<T>::iter PmergeMe<T>::jump(iter it, int steps) {
	std::advance(it, steps);
	return it;
}

template <typename T>
typename PmergeMe<T>::iiter PmergeMe<T>::jump(iiter it, int steps) {
	std::advance(it, steps);
	return it;
}

template <typename T>
T PmergeMe<T>::insert(std::vector<iter> &pend, std::vector<iter> &main, int depth, bool is_odd) {
	int jprev = jacobsthal(1);
	int insert_count = 0;
	int n = 2;

	while (n++) {
		int jcurr = jacobsthal(n);
		int jdiff = jcurr - jprev;
		int offset = 0;

		if (jdiff > static_cast<int>(pend.size()))
			break;
		iiter pend_it = jump(pend.begin(), jdiff - 1);

		while (jdiff--) {
			iiter bound_it = jump(main.begin(), jcurr + insert_count - offset);
			iiter pos = std::upper_bound(main.begin(), bound_it, *pend_it, compare);
			iiter index = main.insert(pos, *pend_it);

			pend_it = pend.erase(pend_it);
			insert_count++;
			std::advance(pend_it, -1);
			if (index - main.begin() == jcurr + insert_count - offset)
				++offset;
		}
		jprev = jcurr;
	}
	for (ssize_t i = pend.size() - 1; i >= 0; i--) {
		iiter cpend = jump(pend.begin(), i);
		iiter cbound = jump(main.begin(), main.size() - pend.size() + i + is_odd);
		iiter index = std::upper_bound(main.begin(), cbound, *cpend, compare);

		main.insert(index, *cpend);
	}
	T copy;
	for (iiter it = main.begin(); it != main.end(); it++) {
		for (int i = 0; i < depth; i++) {
			iter pair_start = *it;
			std::advance(pair_start, i - depth + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}
	return (copy);
}

template <typename T>
void PmergeMe<T>::merge(int depth) {
	int pairs = con.size() / depth;
	if (pairs < 2)
		return;
	bool is_odd = pairs % 2 == 1;
	iter begin = con.begin();
	iter end = jump(begin, depth * (pairs - is_odd));
	for (iter it = begin; it != end; std::advance(it, 2 * depth)) {
		iter curr = jump(it, depth - 1);
		iter next = jump(it, depth * 2 - 1);
		if (!compare(curr, next))
			swap(curr, next);
	}
	merge(depth * 2);
	std::vector<iter> pend;
	std::vector<iter> main;
	main.insert(main.end(), jump(begin, depth - 1));
	main.insert(main.end(), jump(begin, depth * 2 - 1));
	for (int i = 4; i <= pairs; i += 2) {
		pend.insert(pend.end(), jump(begin, depth * (i - 1) - 1));
		main.insert(main.end(), jump(begin, depth * i - 1));
	}
	if (is_odd)
		pend.insert(pend.end(), jump(end, depth - 1));
	T result = insert(pend, main, depth, is_odd);
	std::copy(result.begin(), result.end(), con.begin());
}

template <typename T>
double PmergeMe<T>::operator()() {
	clock_t t1 = clock();
    
	merge(1);

    clock_t t2_vec = clock();
    return (static_cast<double>(t2_vec - t1) / CLOCKS_PER_SEC);
}
