#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    while(true)
    {
        std::cout << "\nEnter Command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (std::cin.eof())
            break;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }  
        std::cin.ignore();

        if(command == "ADD")
            phonebook.addContact();

        else if(command == "SEARCH")
            phonebook.searchContact();
        
        else if(command == "EXIT")
            break;

        else
            std::cout << "invalid command, try again!\n";
    }
    return 0;
}