#include "Zombie.hpp"

int main() 
{
    int N = 5;
    std::string name = "Horde Member";
    
    std::cout << "=== Creating Zombie Horde ===" << std::endl;
    Zombie* horde = zombieHorde(N, name);
    
    std::cout << "\n=== Zombies Announcing ===" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n=== Destroying Horde ===" << std::endl;
    delete[] horde;
    
    std::cout << "\n=== Test with Different Size ===" << std::endl;
    Zombie* smallHorde = zombieHorde(3, "Small Zombie");
    for (int i = 0; i < 3; i++)
    {
        smallHorde[i].announce();
    }
    delete[] smallHorde;
    
    return 0;
}