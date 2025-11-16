#include "HumanB.hpp"

HumanB::HumanB(std::string  Name)
{
    _name = Name;
    _weapon = NULL;
}

void    HumanB::attack( void )
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& Weapon)
{
    _weapon = &Weapon;
}
