#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& other) : AAnimal(other) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) 
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain();
        *brain = *(other.brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const 
{
    return brain;
}

