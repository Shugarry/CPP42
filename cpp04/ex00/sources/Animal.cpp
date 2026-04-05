#include "../headers/Animal.hpp"
#include <iostream>

Animal::Animal(): type("Default animal")
{
	std::cout << "Default constructor for animal called" << std::endl;
}

Animal::Animal(Animal& other): type(other.type)
{
	std::cout << "Copy constructor for animal called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor for animal called" << std::endl;
}

Animal& Animal::operator=(Animal& other)
{
	if (&other != this)
		type = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Nondescript animal sound" << std::endl;
}
