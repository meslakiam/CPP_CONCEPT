#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_energyPoint = 50;
    std::cout << " Default Constractor called for ScavTrap !!" << std::endl;
}

ScavTrap::ScavTrap( int energyPoint )
{
    this->_energyPoint = energyPoint;
}

ScavTrap::ScavTrap( std::string name )
{
    this->_name = name;
    this->_energyPoint = 50;
    std::cout << "Constractor called for ScavTrap !!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap& other ) : ClapTrap()
{
    std::cout << "copy Constractor called for ScavTrap !!" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=( ScavTrap& other )
{
    if(this == &other)
        return ( *this );

    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
    std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
    
    return ( *this );
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap !!" << std::endl;
}

void        ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void        ScavTrap::attack( const std::string& target )
{
    if(_hitPoint <= 0)
    {
        std::cout << "ScavTrap " << _name << " is dead !!" << std::endl;
        return ;
    }
    if(_energyPoint <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy point to attack !!" << std::endl;
        return ;
    }
    
    _energyPoint--;
    std::cout << "ScavTrap " << _name <<  " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    std::cout << "ScavTrap " << _name << " has " << _hitPoint << " Hit Points" << std::endl;
    std::cout << "ScavTrap " << _name <<  " has " << _energyPoint << " Energy Points" << std::endl;

}
