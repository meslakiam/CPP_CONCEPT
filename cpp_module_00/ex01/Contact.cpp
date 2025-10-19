#include "Contact.hpp"

Contact::Contact()
{
    REDCOLOR     = "\x1b[31m";
    GREENCOLOR   = "\x1b[32m";
    YELLOWCOLOR  = "\x1b[33m";
    BLUECOLOR    = "\x1b[34m";
    MAGENTACOLOR = "\x1b[35m";
    CYANCOLOR    = "\x1b[36m";
    BOLD         = "\x1b[1m";
    RESETCOLOR   = "\x1b[0m";
}

bool Contact::CheckPrintChar(std::string line)
{
    for(int i = 0; line[i]; i++)
    {
        if(!isprint(line[i]))
            return (true);
    }
    return (false);
}

void   Contact::PrintWord(std::string word, std::string msg)
{
    int len;
    
    len = word.length();
    if(len > 10)
    {
        std::cout << CYANCOLOR << msg << RESETCOLOR << BOLD << word.substr(0, 9) << "." << RESETCOLOR;
    }
    else
    {
        std::cout << CYANCOLOR << msg << RESETCOLOR << BOLD << word << RESETCOLOR;
        if(len < 10)
        {
            while (len < 10)
            {
                std::cout << " ";
                len++;
            }
        }
    }
} 
    
void    Contact::set_contact(std::string SetFirstName, std::string SetLastName , std::string SetNickName, std::string SetDarkestSecret, std::string SetPhoneNumber)
{
    FirstName = SetFirstName;
    LastName = SetLastName;
    NickName = SetNickName;
    DarkestSecret = SetDarkestSecret;
    PhoneNumber = SetPhoneNumber;
}

void    Contact::display_one_contact()
{
    PrintWord(FirstName, "First Name: ");
    std::cout << std::endl;
    PrintWord(LastName, "Last Name: ");
    std::cout << std::endl;
    PrintWord(NickName, "Nick Name: ");
    std::cout << std::endl;
    PrintWord(DarkestSecret, "Darkest Secret: ");
    std::cout << std::endl;
    PrintWord(PhoneNumber, "Phone Number: ");
    std::cout << std::endl;
}

void    Contact::display_contacts()
{
    PrintWord(FirstName, "First Name: ");
    std::cout << YELLOWCOLOR << BOLD << " | " << RESETCOLOR;
    PrintWord(LastName, "Last Name: ");
    std::cout << YELLOWCOLOR << BOLD << " | " << RESETCOLOR;
    PrintWord(NickName, "Nick Name: ");
}
