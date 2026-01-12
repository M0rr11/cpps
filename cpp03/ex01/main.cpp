#include  "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\nScavTrap:" << std::endl;
    ScavTrap scav("Scavvy");
    ScavTrap scavCopy(scav);
    scav.attack("Target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}

