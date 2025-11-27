#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("no name"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "Default Constractor called !!" << std::endl;
}
ClapTrap::ClapTrap( std::string name ) 
    :_name(name),  _hitPoint(10) ,  _energyPoint(10), _attackDamage(0)
{
    std::cout << "Constractor called !!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other)
{
    std::cout << "copy Constractor called !!" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=( ClapTrap& other )
{
    if(this == &other)
        return ( *this );

    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
    std::cout << "Copy assignment operator called" << std::endl;

    return ( *this ); 
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called !!" << std::endl;
}

void        ClapTrap::attack( const std::string& target )
{   
    if(_hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead !!" << std::endl;
        return ;
    }
    if(_energyPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy point to attack !!" << std::endl;
        return ;
    }
    
    _energyPoint--;
    std::cout << "ClapTrap " << _name <<  " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _hitPoint << " Hit Points" << std::endl;
    std::cout << "ClapTrap " << _name <<  " has " << _energyPoint << " Energy Points" << std::endl;

}

void        ClapTrap::takeDamage( unsigned int amount )
{
    if(_hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead !!" << std::endl;
        return ;
    }
    if(amount < 0 || amount >= 2147483627)
    {
        std::cout << "Invalid Damage Input !!" << std::endl;
        return ;
    }
    _hitPoint -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " Damage Points !" << std::endl;
    if(_hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead !!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " has " << _hitPoint << " Hit Points" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _energyPoint << " Energy Points" << std::endl;

}

void        ClapTrap::beRepaired( unsigned int amount )
{
    if(_hitPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead !!" << std::endl;
        return ;
    }
    if(_energyPoint <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy point to repaired !!" << std::endl;
        return ;
    }
    if(amount < 0 || amount >= 2147483627)
    {
        std::cout << "Invalid Repaired Input !!" << std::endl;
        return ;
    }

    _hitPoint += amount;
    _energyPoint--;
    std::cout << "ClapTrap " << _name << " repaired " << " himself with " << amount << " Repaired Point" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _hitPoint << " Hit Points" << std::endl;
    std::cout << "ClapTrap " << _name << " has " << _energyPoint << " Energy Points" << std::endl;

}
