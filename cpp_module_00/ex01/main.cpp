#include "PhoneBook.hpp"

void    PrintMsg(PhoneBook   PhB)
{
    Contact C = PhB.GetContact();

    std::cout << C.YELLOWCOLOR << C.BOLD  << "Enter a command (ADD, SEARCH, or EXIT): ";
    std::cout << C.RESETCOLOR;
        
}

void    PrintError(std::string UserCmd)
{
    PhoneBook   phonebook;
    Contact     C;

    C = phonebook.GetContact();
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
        getline(std::cin, UserCmd);
        if(Contact::CheckPrintChar(UserCmd))
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
