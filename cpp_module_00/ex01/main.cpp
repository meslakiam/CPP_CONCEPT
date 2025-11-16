#include "PhoneBook.hpp"
#include <iostream>

void    PrintMsg(PhoneBook   PhB)
{
    Contact C = PhB.GetContact(0);

    std::cout << C.YELLOWCOLOR << C.BOLD  << "Enter a command (ADD, SEARCH, or EXIT): ";
    std::cout << C.RESETCOLOR;
}

void    PrintError(std::string UserCmd)
{
    PhoneBook   phonebook;
    Contact     C;

    C = phonebook.GetContact(0);
    std::cout << C.REDCOLOR << C.BOLD << "Error: Invalid command '";
    std::cout << UserCmd << "'" << C.RESETCOLOR << std::endl;
}

int main()
{
    PhoneBook   phonebook;
    std::string UserCmd;

    while(1)
    {
        PrintMsg(phonebook);
        if(!getline(std::cin, UserCmd))
        {
            if(std::cin.eof())
            {
                std::cin.clear();
                freopen("/dev/tty","r", stdin);
                std::cout << std::endl;
            }
        }
        else if(Contact::CheckPrintChar(UserCmd))
            PrintError("(non-printable) characters");
        else if(UserCmd == "ADD")
            phonebook.ADD();
        else if(UserCmd == "SEARCH")
            phonebook.SEARCH();
        else if(UserCmd == "EXIT")
            phonebook.EXIT();
        else
            PrintError(UserCmd);
    }
    return 0;
}
