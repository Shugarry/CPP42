#include "../headers/ScavTrap.hpp"

int main()
{
    ScavTrap a;
    ScavTrap b("scav");
    ScavTrap c(b);
    a = b;
    b.attack("enemy");
    b.guardGate();

    return 0;
}
