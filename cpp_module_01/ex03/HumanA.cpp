#include "HumanA.hpp"

HumanA::HumanA(std::string  Name, Weapon& weapon) : _weapon(weapon)
{
    _name = Name;
}

void    HumanA::attack( void )
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
