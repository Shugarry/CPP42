#include "../headers/Zombie.hpp"
#include <iostream>

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed" << std::endl;
}
void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


