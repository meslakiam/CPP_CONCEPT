#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class   PhoneBook {

    private:
        Contact contacts[8];
        int i;

        bool        CheckContactIndex(std::string line);
        int         CheckPlusInNum(std::string line);
        bool        InvalidInput(std::string line, std::string type);
        std::string ReadLine(std::string msg, std::string type);
        void        DisplaySpecificContact();

    public:
        PhoneBook();
        Contact GetContact(int i);
        void    ADD();
        void    SEARCH();
        void    EXIT();
    };

#endif