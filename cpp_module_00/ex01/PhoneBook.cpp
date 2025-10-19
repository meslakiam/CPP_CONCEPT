
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    i = 0;
}

Contact PhoneBook::GetContact()
{
    return contacts[0];
}

void    PhoneBook::ADD()
{
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string DarkestSecret;
    std::string PhoneNumber;

    FirstName = ReadLine("First Name", "string");
    LastName = ReadLine("Last Name", "string");
    NickName = ReadLine("Nick Name", "string");
    DarkestSecret = ReadLine("Darkest Secret", "string");
    PhoneNumber = ReadLine("Phone Number", "number");
    if(i == 7)
    i = 0;
    contacts[i].set_contact(FirstName, LastName, NickName, DarkestSecret, PhoneNumber);
    i++;
}

 void   PhoneBook::SEARCH()
{
    int i = 0;

    while (i < 7)
    {
        std::cout << GetContact().CYANCOLOR << "Contact: " << i + 1 << GetContact().RESETCOLOR;
        std::cout << GetContact().YELLOWCOLOR << GetContact().BOLD << " | " << GetContact().RESETCOLOR;
        contacts[i].display_contacts();
        std::cout << std::endl;
        i++;
    }
    DisplaySpecificContact();
}

void    PhoneBook::EXIT()
{
    std::cout << GetContact().GREENCOLOR << "exiting successfully" << GetContact().RESETCOLOR << std::endl;
    exit(0);
}

int PhoneBook::CheckPlusInNum(std::string line)
{
    if(line[0] == '+' && line[1])
            return (1);
    return (0);
}

bool    PhoneBook::CheckContactIndex(std::string line)
{
    int     index;
    Contact C = GetContact();

    for(int i = 0; line[i]; i++)
        {
            if(!isdigit(line[i]))
            {
                std::cout << C.REDCOLOR << C.BOLD << "Invalid Index !!" << C.RESETCOLOR << std::endl;
                return (true);
            }
        }
    index = std::atoi(line.c_str());
    if(index <= 0 || index > 7)
    {
        

        std::cout << C.REDCOLOR << C.BOLD << "Invalid Index !!" << C.RESETCOLOR << std::endl;
        return (true);
    }
    return (false);
}

bool    PhoneBook::InvalidInput(std::string line, std::string type)
{
    if(line.empty())
        return (true);
    if(type == "number")
    {
        for(int i = CheckPlusInNum(line); line[i]; i++)
        {
            if(!isdigit(line[i]))
                return (true);
        }
    }
    else if(type == "string")
        return (Contact::CheckPrintChar(line));
    else if(type == "index")
        return (CheckContactIndex(line));
    return (false);
}

std::string    PhoneBook::ReadLine(std::string msg, std::string type)
{
    std::string line;

    while (InvalidInput(line, type))
    {
        std::cout << GetContact().MAGENTACOLOR << "Enter " << msg << ": " << GetContact().RESETCOLOR;
        getline(std::cin, line);
    }
    return (line);
}

void    PhoneBook::DisplaySpecificContact()
{
    std::string UserInput;
    int         index;

    UserInput = ReadLine("Contact Index From [1 to 7]", "index");
    // .c_str() convert a string to char * by returning the pointer to the first char in  the string 
    index = std::atoi(UserInput.c_str()) - 1;
    contacts[index].display_one_contact();
}
