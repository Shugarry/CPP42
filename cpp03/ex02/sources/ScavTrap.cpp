#include "../headers/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called for ScavTrap" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrized constructor called for ScavTrap" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy operator called for ScavTrap" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (hit_points == 0)
	{
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy left" << std::endl;
		return;
	}
	--energy_points;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
			  << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode" << std::endl;
}
