#include "../headers/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Default constructor for WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Copy constructor for WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor for WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{

	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "Copy operator for WrongCat called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "NYAA NYAA NYAA NYAA NYAA NYAA NYAA NYAA NYAA" << std::endl;
}
