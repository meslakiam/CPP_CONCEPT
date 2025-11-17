#include "Harl.hpp"

int     Harl::GetIndex(std::string level )
{
    std::string table[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    for(int i = 0; i < 4; i++)
    {
        if(table[i] == level)
            return (i);
    }
    return (-1);
}

void    Harl::FilterComplain( std::string level )
{
    int index;
    
    index = GetIndex(level);
    switch (index)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << "I really do!\n" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put ";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";  
    std::cout << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I’ve been coming for years, whereas you started working here just last month.\n";                
    std::cout << std::endl;
}
void    Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
