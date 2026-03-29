#include "../headers/HumanA.hpp"
#include <iostream>

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.get_type() << std::endl;
}
