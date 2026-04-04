#include "../headers/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor called for FragTrap" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrized constructor called for FragTrap" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy operator called for FragTrap" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " gives you a high five" << std::endl;
}
