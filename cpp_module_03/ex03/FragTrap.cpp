#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_hitPoint = 100;
    this->_attackDamage = 30;
    std::cout << " Default Constractor called for FragTrap !!" << std::endl;
}

FragTrap::FragTrap(int hitPoint,int  attackDamage)
{
    this->_hitPoint = hitPoint;
    this->_attackDamage = attackDamage;
}

FragTrap::FragTrap(std::string name) 
{
    this->_name = name;
    this->_hitPoint = 100;
    this->_attackDamage = 30;

    std::cout << " Constractor called for FragTrap !!" << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap()
{
    std::cout << "copy Constractor called for FragTrap !!" << std::endl;
    *this = other;
}

FragTrap&   FragTrap::operator=(FragTrap& other)
{
    if(this == &other)
        return ( *this );
    
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
    std::cout << "Copy assignment operator called for FragTrap" << std::endl;

    return ( *this );
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called for FragTrap !!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "High-Five ✋" << std::endl;
}
