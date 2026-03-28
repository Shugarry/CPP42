#include "../headers/Zombie.hpp"
#include <iostream>

int main()
{
	Zombie *horde = zombieHorde(10, "Bobby");

	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": ";
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
