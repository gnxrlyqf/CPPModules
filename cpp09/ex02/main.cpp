#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <iomanip>

int main(int ac, char **av) {
	if (ac == 1) {
		return (1);
	}
	try {
		PmergeMe< std::vector<int> > vec(av + 1);
		PmergeMe< std::deque<int> > deq(av + 1);

		std::cout << "Before:	" << vec << std::endl;
		double vec_time = vec();
		std::cout << "After:	" << vec << std::endl;
		double deq_time = deq();
		std::cout << "Time to process a range of "
		<< vec.getContainer().size() << " with std::vector: " << std::fixed << std::setprecision(6) << vec_time << " μs" << std::endl;
		std::cout << "Time to process a range of "
		<< deq.getContainer().size() << " with std::deque: " << std::fixed << std::setprecision(6) << deq_time << " μs" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}