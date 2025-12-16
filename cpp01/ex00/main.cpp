#include "Zombie.hpp"

int main()
{
    std::cout << "=== Creating zombie on HEAP ===" << std::endl;
    Zombie* heapZombie = newZombie("Harry");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n=== Creating zombie on STACK ===" << std::endl;
    randomChump("Steve");
    std::cout << "(Steve was automatically destroyed)\n";
    
    std::cout << "\n=== Creating another heap zombie ===" << std::endl;
    Zombie* zombie2 = newZombie("Persistent Pete");
    zombie2->announce();

    std::cout << "\n=== Program ending ===" << std::endl;
    delete zombie2;

    return 0;
}
