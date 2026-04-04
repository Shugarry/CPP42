#include "../headers/FragTrap.hpp"

int main()
{
    FragTrap a;
    FragTrap b("frag");
    FragTrap c(b);
    a = b;
    b.attack("enemy");
    b.highFivesGuys();

    return 0;
}
