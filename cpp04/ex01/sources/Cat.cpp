#include "../headers/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Copy constructor for Cat called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Destructor for Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Copy operator for Cat called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW MEOW MEOW MEOW MEOW MEOW" << std::endl;
}
