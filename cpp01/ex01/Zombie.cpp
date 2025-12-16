#include "Zombie.hpp"

Zombie::Zombie() 
{
    name = "Unnamed";
}

Zombie::Zombie(std::string zombieName) {
    name = zombieName;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName) {
    name = zombieName;
}