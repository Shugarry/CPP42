#include "../headers/ClapTrap.hpp"

int main()
{
	ClapTrap *tmp = new ClapTrap;
	delete tmp;

    ClapTrap a("Nuts");
    ClapTrap b("Bolts");

    a.attack("Bolts");
    b.takeDamage(5);

    b.beRepaired(3);

    ClapTrap c(a);
    ClapTrap d;
    d = b;

    c.attack("Bolts");
    d.beRepaired(2);

    return 0;
}
