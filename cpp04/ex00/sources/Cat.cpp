#include "../headers/Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Default constructor for Cat called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat& other)
{
	std::cout << "Copy constructor for Cat called" << std::endl;
	type = other.type;
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat called" << std::endl;
}

Cat& Cat::operator=(Cat& other)
{
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW MEOW MEOW MEOW MEOW MEOW" << std::endl;
}
