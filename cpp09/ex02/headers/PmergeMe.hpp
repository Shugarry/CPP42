#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int ac, char** av);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parse_args(int ac, char** av);
		void sort();

	private:
		std::vector<int> vector;
		std::deque<int> deque;
		bool parsed;
		
		template <typename T>
		void recursive_step(T& container);
		void sort_vector();
		void sort_deque();
};

#endif
