#include "../headers/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Parametrized constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),
	  attack_damage(other.attack_damage)
{
	std::cout << "Copy constructor called for ClapTrap" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy operator called for ClapTrap" << std::endl;

	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left" << std::endl;
		return;
	}
	--energy_points;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			  << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int new_hp;

	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (amount >= hit_points)
		new_hp = 0;
	else
		new_hp = hit_points - amount;
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage. HP: " << hit_points << " -> " << new_hp << std::endl;
	hit_points = new_hp;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int new_hp;

	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left" << std::endl;
		return;
	}
	--energy_points;
	new_hp = (unsigned int)(hit_points + amount);
	if (new_hp > 10 || amount > 10)
		new_hp = 10;
	std::cout << "ClapTrap " << name << " gets repaired by " << amount
			  << " points. HP: " << hit_points << " -> " << new_hp << std::endl;
	hit_points = new_hp;
}
