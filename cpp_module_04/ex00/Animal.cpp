#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "default constractor called for Animal !!" << std::endl;
}

Animal::Animal(Animal& other)
{
    *this = other;
    std::cout << "copy constractor called for Animal !!" << std::endl;
}

Animal& Animal::operator=(Animal& other)
{
    if( this == &other )
        return ( *this );
    
    this->_type = other._type;
    std::cout << "Copy assignment operator called for Animal" << std::endl;

    return ( *this );
}

Animal::~Animal()
{
    std::cout << "Destructor called for Animal !!" << std::endl;
}

std::string     Animal::getType() const
{
    return ( this->_type );
}

void    Animal::makeSound() const
{
    std::cout << "Animal makes sounds " << std::endl;
}
