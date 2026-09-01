#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

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

		template <typename T>
		int binary_search(T& container, int left, int right, int target);
		template <typename T>
		int find_limit(int value, T& tmp_main);
		template <typename T>
		void insertion_step(T& main, T& pending, T& tmp_main);

	private:
		std::vector<int> vector;
		std::deque<int> deque;
		int comparisons;
		bool parsed;
		
		template <typename T>
		void recursive_step(T& container);
		void sort_vector();
		void sort_deque();
};

#endif
