#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>

class   Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string DarkestSecret;
        std::string PhoneNumber;

        void    PrintWord(std::string word, std::string msg);

    public:
        const char* REDCOLOR;
        const char* GREENCOLOR;
        const char* YELLOWCOLOR;
        const char* BLUECOLOR;
        const char* MAGENTACOLOR;
        const char* CYANCOLOR;
        const char* BOLD;
        const char* RESETCOLOR;
        Contact();
        static bool    CheckPrintChar(std::string line);
        void    set_contact(std::string SetFirstName, std::string SetLastName , std::string SetNickName, std::string SetDarkestSecret, std::string SetPhoneNumber);
        void    display_one_contact();
        void    display_contacts();

};

#endif