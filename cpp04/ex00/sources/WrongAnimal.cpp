#include "../headers/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("Default animal")
{
	std::cout << "Default constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << "Copy constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (&other != this)
		type = other.type;
	std::cout << "Copy operator for WrongAnimal called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Nondescript WrongAnimal sound" << std::endl;
}
