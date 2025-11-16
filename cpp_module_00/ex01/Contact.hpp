#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>



class   Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string DarkestSecret;
        std::string PhoneNumber;

        void    PrintWord(std::string word, std::string msg);
        void    PrintLine(std::string word, std::string msg);

    public:
        std::string REDCOLOR;
        std::string GREENCOLOR;
        std::string YELLOWCOLOR;
        std::string BLUECOLOR;
        std::string MAGENTACOLOR;
        std::string CYANCOLOR;
        std::string BOLD;
        std::string RESETCOLOR;
        Contact();
        static bool    CheckPrintChar(std::string line);
        void           set_contact(std::string SetFirstName, std::string SetLastName,
                                    std::string SetNickName, std::string SetDarkestSecret, std::string SetPhoneNumber);
        void           display_one_contact();
        void           display_contacts();
};

#endif