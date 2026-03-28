#include "../headers/Zombie.hpp"

int main()
{
	Zombie *z = newZombie("Fred");
	z->announce();
	delete z;

	randomChump("Juanjo");

	return 0;
}
