#include "../headers/PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe(): parsed(false)
{
}

PmergeMe::PmergeMe(int ac, char** av)
{
	parse_args(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe& other): vector(other.vector), deque(other.deque), parsed(other.parsed)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vector = other.vector;
		deque = other.deque;
		parsed = other.parsed;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static bool valid(std::string arg)
{
	if (arg.empty() || (arg[0] < '0' && arg[0] > '9'))
		return false;
	return true;
}

void PmergeMe::parse_args(int ac, char** av)
{
	if (!av)
		throw std::runtime_error("Error: no args");
	for (size_t i = 0; i < ac; i++)
	{
		if (valid(av[i]) == false)
			throw std::runtime_error(std::string("Error: invalid args -> ") + av[i]);
		vector.push_back(std::atoi(av[i]));
		deque.push_back(std::atoi(av[i]));
	}
	parsed = true;
}

static bool sorted(std::vector<int> vector)
{
    for (size_t i = 0; i < vector.size() - 1; ++i)
        if (vector[i] > vector[i + 1])
            return false;
    return true;
}

void PmergeMe::sort()
{
	if (sorted(vector))
	{
		std::cout << "Already sorted, no calculations to perform" << "\n";
		return ;
	}
	// sort_vector();
	// sort_deque();
	recursive_step(vector);
}

// K(n) = K(n - 1) + 2K(n - 2)
static int find_jacobsthal(int k)
{
	int sequence[] = {
		0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,
		2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051,
		1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485,
		178956971, 357913941, 715827883, 1431655765
	};
	if (k > 33)
		return 0;
	return sequence[k];
}

template <typename T>
static void insertion_step(T& main, T& pending, T& tmp_main)
{
	if (pending.empty())
		return ;
	

	size_t i;
	// insert first pending
	for (i = 0; i < pending.size(); i++)
		if (pending[i] == main[0])
			break ;
	main.push_front(pending[i]);
	// calculate jacobsthal insertion bounds now (1, 3) (3, 5) and so on
}

// main: starts with the smallest element of the smallest pair followed by every largest number of every remaining pair including the initial pair
// pend: contains every remaining smallest number
template <typename T>
void PmergeMe::recursive_step(T& container)
{
	if (container.size() <= 1)
		return ;

	T main, pending, tmp_main;
	int comparisons = 0;

	for (size_t i = 0; i < container.size() - 1; i += 2)
	{
		if (container[i] > container[i + 1])
		{
			main.push_back(container[i]);
			tmp_main.push_back(container[i]);
			pending.push_back(container[i + 1]);
			comparisons++;
		}
		else
		{
			main.push_back(container[i + 1]);
			tmp_main.push_back(container[i + 1]);
			pending.push_back(container[i]);
			comparisons++;
		}
	}
	if (container.size() % 2 == 1)
		pending.push_back(container.back());

	recursive_step(main);

	insertion_step(main, pending, tmp_main);

	container = main;
}

void PmergeMe::sort_vector()
{
	
}

void PmergeMe::sort_deque()
{

}
