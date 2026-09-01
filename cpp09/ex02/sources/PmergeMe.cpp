#include "../headers/PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <sys/select.h>

PmergeMe::PmergeMe(): comparisons(0), parsed(false)
{
}

PmergeMe::PmergeMe(int ac, char** av): comparisons(0)
{
	parse_args(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe& other): vector(other.vector), deque(other.deque), comparisons(other.comparisons), parsed(other.parsed)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vector = other.vector;
		deque = other.deque;
		parsed = other.parsed;
		comparisons = other.comparisons;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static bool duplicate(char* str, std::vector<int>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (atoi(str) == vector[i])
			return true;
	}
	return false;
}

static bool valid(std::string arg)
{
	if (arg.empty() || (arg[0] < '0' || arg[0] > '9'))
		return false;
	return true;
}

void PmergeMe::parse_args(int ac, char** av)
{
	if (!av)
		throw std::runtime_error("Error: no args");
	for (int i = 1; i < ac; i++)
	{
		if (valid(av[i]) == false)
			throw std::runtime_error(std::string("Error: invalid args -> ") + av[i]);
		if (duplicate(av[i], vector) == true)
			throw std::runtime_error(std::string("Error: duplicate -> ") + av[i]);
		vector.push_back(atoi(av[i]));
		deque.push_back(atoi(av[i]));
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

	std::cout << "Before:" ;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << " " << vector[i];
	std::cout << "\n";

	if (sorted(vector))
	{
		std::cout << "Already sorted, no calculations to perform" << "\n";
		return ;
	}

    struct timeval vector_start, vector_end, deque_start, deque_end;

	gettimeofday(&vector_start, NULL);
	sort_vector();
	gettimeofday(&vector_end, NULL);

	comparisons = 0; // reset or it gets counted twice

	gettimeofday(&deque_start, NULL);
	sort_deque();
	gettimeofday(&deque_end, NULL);

    long vector_total = (vector_end.tv_sec - vector_start.tv_sec) * 1000000 + vector_end.tv_usec - vector_start.tv_usec;
    long deque_total = (deque_end.tv_sec - deque_start.tv_sec) * 1000000 + deque_end.tv_usec - deque_start.tv_usec;

	std::cout << "After:" ;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << " " << vector[i];
	std::cout << "\n";

	std::cout << "Comparisons: " << comparisons << "\n";
	std::cout << "Time to process with std::vector: " << vector_total << " us\n";
	std::cout << "Time to process with std::deque: " << deque_total << " us\n";
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
int PmergeMe::binary_search(T& container, int left, int right, int target)
{
	if (right == -1)
		right = container.size();
	if (left > right)
		return left;

	int middle = left + ((right - left) / 2);

	comparisons++;
	if (container[middle] == target)
		return middle;
	else if (container[middle] < target)
		return binary_search(container, middle + 1, right, target);
	else
		return binary_search(container, left, middle - 1, target);
	
}

template <typename T>
int PmergeMe::find_limit(int value, T& tmp_main)
{

	for (size_t i = 0; i < tmp_main.size(); i++)
		if (tmp_main[i] == value)
			return i;
	return -1; 
}

// calculate jacobsthal insertion bounds now (1, 3) (3, 5) and so on
template <typename T>
void PmergeMe::insertion_step(T& main, T& pending, T& tmp_main)
{
	if (pending.empty())
		return ;

	T chain = main;

	// insert first pending (free)
	int i = find_limit(chain[0], tmp_main);
	main.insert(main.begin(), pending[i]);


	int jacob_index = 1;
	int inserted = 1;
	while (inserted < (int)pending.size())
	{
		int lower_bound = find_jacobsthal(jacob_index - 1);
		int upper_bound = find_jacobsthal(jacob_index) - 1;
		int index_bound = std::min(upper_bound, (int)pending.size() - 1); // calculate jacobsthal insertion bounds now (1, 3) (3, 5) and so on

		for (int j = index_bound; j >= lower_bound && j > 0; j--)
		{
			int og_index = find_limit(chain[j], tmp_main);
			int right = find_limit(chain[j], main);
			int insert_position = binary_search(main, 0, right, pending[og_index]);
			main.insert(main.begin() + insert_position, pending[og_index]);
			inserted++;
		}
		jacob_index++;
	}
}

// main: starts with the smallest element of the smallest pair followed by every largest number of every remaining pair including the initial pair
// pend: contains every remaining smallest number
template <typename T>
void PmergeMe::recursive_step(T& container)
{
	if (container.size() <= 1)
		return ;

	T main, pending, tmp_main;

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
	recursive_step(vector);
}

void PmergeMe::sort_deque()
{
	recursive_step(deque);
}
