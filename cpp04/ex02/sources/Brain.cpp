#include "../headers/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Default constructor for Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor for Brain called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy operator for Brain called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain called" << std::endl;
}

void Brain::set_idea(std::string idea, int i)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}

std::string Brain::get_idea(int i) const
{
	if (i >= 0 && i < 100)
		return ideas[i];
	return "";
}
