#include "../headers/Zombie.hpp"
#include <iostream>

void Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed" << std::endl;
}
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


