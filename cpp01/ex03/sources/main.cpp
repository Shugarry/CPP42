#include "../headers/HumanA.hpp"
#include "../headers/HumanB.hpp"
#include <iostream>
#include "../headers/Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		std::cout << "weapon = " << club.get_type() << std::endl;
		HumanA bob("Bob", club);
		bob.attack();
		club.set_type("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.set_weapon(club);
		jim.attack();
		club.set_type("some other type of club");
		jim.attack();
	}
	return 0;
}
