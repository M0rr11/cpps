#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
    countContact = 0;
    nextIndex = 0;
}

void    PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Field cannot be empty!\n";
        return;
    }
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Field cannot be empty!\n";
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Field cannot be empty!\n";
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std::cout << "Phone number must contain only digits, Try again!\n";
            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
        }
    }
    if (input.empty()) {
        std::cout << "Field cannot be empty!\n";
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Field cannot be empty!\n";
        return;
    }
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if(countContact < 8)
        countContact++;

    std::cout << "Contact added successefully!\n";
}

std::string formatField(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    PhoneBook::searchContact()
{
    if(countContact == 0)
    {
        std::cout << "PhoneBook is empty!\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < countContact; i++)
    {
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        std::cout << std::setw(10) << std::right << formatField(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << formatField(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << formatField(contacts[i].getNickname()) <<  "|" << std::endl;
    }

    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore();
    index -= 1;

    if(index >= 0 && index < countContact)
    {
        std::cout << "First name: "<< contacts[index].getFirstName() << std::endl;
        std::cout << "Last name: "<< contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: "<< contacts[index].getNickname() << std::endl;
        std::cout << "Phone number: "<< contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: "<< contacts[index].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid Index!\n";
}