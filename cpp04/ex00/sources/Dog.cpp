#include "../headers/Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Default constructor for Dog called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog& other)
{
	std::cout << "Copy constructor for Dog called" << std::endl;
	type = other.type;
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog called" << std::endl;
}

Dog& Dog::operator=(Dog& other)
{
	Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF WOOF WOOF WOOF WOOF WOOF" << std::endl;
}
