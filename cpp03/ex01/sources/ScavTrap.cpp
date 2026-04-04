#include "../headers/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : name("default"), hit_points(100), energy_points(50), attack_damage(20)
{
	std::cout << "Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: name(name), hit_points(100), energy_points(50), attack_damage(20)
{
	std::cout << "Parametrized constructor called for ScavTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),
	  attack_damage(other.attack_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy operator called" << std::endl;

	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return;
	}
	--this->energy_points;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
			  << this->attack_damage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	int new_hp;

	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (amount >= this->hit_points)
		new_hp = 0;
	else
		new_hp = this->hit_points - amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount
			  << " points of damage. HP: " << this->hit_points << " -> " << new_hp << std::endl;
	this->hit_points = new_hp;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int new_hp;

	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return;
	}
	--this->energy_points;
	new_hp = (unsigned int)(this->hit_points + amount);
	if (new_hp > 10 || amount > 10)
		new_hp = 10;
	std::cout << "ClapTrap " << this->name << " gets repaired by " << amount
			  << " points. HP: " << this->hit_points << " -> " << new_hp << std::endl;
	this->hit_points = new_hp;
}
