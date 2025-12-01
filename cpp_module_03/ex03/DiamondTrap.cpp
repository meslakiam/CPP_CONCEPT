#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "no name";
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;

    std::cout << " Default Constractor called for DiamondTrap !!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = name;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;

    std::cout << " Constractor called for DiamondTrap !!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(), ScavTrap(), FragTrap()
{    
    std::cout << "copy Constractor called for DiamondTrap !!" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other)
{
    if ( this == &other )
        return ( *this );
    
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
    std::cout << "Copy assignment operator called for DiamondTrap" << std::endl;

    return ( *this );
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor called for DiamondTrap !!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap: " << this->_name << std::endl;
    std::cout << "ClapTrap: " << ClapTrap::_name << std::endl;
}
