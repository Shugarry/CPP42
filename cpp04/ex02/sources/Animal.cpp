#include "../headers/Animal.hpp"
#include <iostream>

Animal::Animal(): type("Default Animal")
{
	std::cout << "Default constructor for Animal called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << "Copy constructor for Animal called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (&other != this)
		type = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}
