#include  "FragTrap.hpp"
#include  "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Superman");
    clap.attack("LexLuthor");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(8);
    
    std::cout << "\nScavTrap:" << std::endl;
    ScavTrap scav("Roben");
    ScavTrap Roben2(scav);
    scav.attack("Superman");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\nFragTrap:" << std::endl;
    FragTrap frag("Batman");
    frag.attack("Roben");
    frag.takeDamage(15);
    frag.beRepaired(5);
    frag.highFivesGuys();

    return 0;
}
