#include "../headers/HumanB.hpp"
#include <iostream>

void HumanB::set_weapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->weapon)
		std::cout << name << " attacks with their " << weapon->get_type() << std::endl;
	else
		std::cout << name << "has no weapon" << std::endl;
}
