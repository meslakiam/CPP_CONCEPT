#include "Harl.hpp"

void    Harl::complain( std::string level )
{
    int num;

    void    (Harl::*talbe[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::stringstream(level) >> num;
    if(num >= 0 && num < 4)
    {
        Harl H;
        (H.*talbe[num])();
    }
}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << "I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!";  
    std::cout << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
    std::cout << "years, whereas you started working here just last month.";                
    std::cout << std::endl;
}
void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
