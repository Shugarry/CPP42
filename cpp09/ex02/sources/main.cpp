#include "../headers/PmergeMe.hpp"

#include <iostream>

int main(int ac, char **av)
{
	if (ac <= 3)
	{
		std::cout << "error: need at least two numbers\n";
		std::cout << "format: ./pmergeme <int> <int> <int> ...";
		return 1;
	}

	PmergeMe sort;
	try
	{
		sort.parse_args(ac, av);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
	sort.sort();
}
