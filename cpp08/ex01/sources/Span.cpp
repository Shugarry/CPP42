#include "../headers/Span.hpp"
#include <algorithm>

Span::Span(): n(0)
{
}

Span::Span(unsigned int n): n(n)
{
}


Span::Span(const Span& other):n(other.n), vector(other.vector)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		n = other.n;
		vector = other.vector;
	}
	return *this;
}

Span::~Span()
{
}

void Span::add_number(unsigned int x)
{
	if (vector.size() >= n || n == 0)
	{
		throw ContainerFullException();
	}
	vector.push_back(x);
}

void Span::add_numbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
    if (vector.size() + std::distance(begin, end) > n)
        throw ContainerFullException();

    vector.insert(vector.end(), begin, end);
}

int Span::shortest_span()
{
    std::vector<unsigned int> tmp(vector);

    if (vector.size() < 2)
        throw NotEnoughElementsException();
    std::sort(tmp.begin(), tmp.end());
    unsigned int shortest = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); ++i)
        shortest = std::min(shortest, tmp[i] - tmp[i - 1]);

    return shortest;
}

int Span::longest_span()
{
	unsigned int largest;
	unsigned int smallest;

	if (vector.size() < 2)
	{
		throw NotEnoughElementsException();
	}
	largest = *vector.begin();
	smallest = *vector.begin();
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (largest < *it)
			largest = *it;
		if (smallest > *it)
			smallest = *it;
	}
	return largest - smallest;
}
