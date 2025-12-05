#include "Character.hpp"

Character::Character()
{
    this->_name = "default name";
    for (size_t i = 0; i < 4; i++)
         this->_inventory[i] = 0;
}

Character::Character( std::string  name )
{
    this->_name = name;
    for (size_t i = 0; i < 4; i++)
         this->_inventory[i] = 0;
}

Character::Character( const Character& other )
{
    *this = other;
}

Character&     Character::operator=( const Character& other )
{
    if( this == &other )
        return ( *this );

    this->_name = other._name;
    for (size_t i = 0; i < 4; i++)
    {
        if(this->_inventory[i])
            delete this->_inventory[i];
    }
    for (size_t i = 0; i < 4; i++)
    {
        if(other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }

    return ( *this );
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if(this->_inventory[i])
        {
            delete this->_inventory[i];
        }
    }
}

std::string const&  Character::getName() const
{
    return ( this->_name );
}

void    Character::equip(AMateria* m)
{
    if(!m)
        return ;

    for (size_t i = 0; i < 4; i++)
    {
        if(this->_inventory[i] == 0)
        {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void    Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
    {
        this->_inventory[idx] = 0;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if(idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}
