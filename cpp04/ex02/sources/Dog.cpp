#include "../headers/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Copy constructor for Dog called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Destructor for Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Copy operator for Dog called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF WOOF WOOF WOOF WOOF WOOF" << std::endl;
}

void Dog::set_idea(std::string idea, int i)
{
	brain->set_idea(idea, i);
}

std::string Dog::get_idea(int i) const
{
	return brain->get_idea(i);
}
