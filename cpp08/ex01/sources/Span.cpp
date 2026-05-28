#include "../headers/Span.hpp"

Span::Span(): n(0)
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

int Span::shortest_span()
{
	int smallest;
	int largest;

	if (vector.size() < 2)
	{
		throw NotEnoughElementsException();
	}
	smallest = *vector.begin();
	largest = *vector.begin();
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (smallest < *it)
			smallest = *it;
		if (largest > *it)
			largest = *it;
	}
	return largest - smallest;
}

int Span::longest_span()
{
	int smallest;
	int largest;

	if (vector.size() < 2)
	{
		throw NotEnoughElementsException();
	}
	smallest = *vector.begin();
	largest = *vector.begin();
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (smallest < *it)
			smallest = *it;
		if (largest > *it)
			largest = *it;
	}
	return largest - smallest;
}
