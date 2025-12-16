#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int countContact;
        int nextIndex;

    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
};

#endif