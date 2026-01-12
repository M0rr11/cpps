#include  "ClapTrap.hpp"

int main()
{
    ClapTrap ct1("Clappy");
    ClapTrap ct2 = ct1;
    ClapTrap ct4("Maggy");
    ClapTrap ct3;

    ct3 = ct1;
    ct2 = ct4;

    ct1.attack("Target1");
    ct1.takeDamage(5);
    ct1.beRepaired(3);
    ct1.takeDamage(10);
    ct1.attack("Target2");

    return 0;
}

