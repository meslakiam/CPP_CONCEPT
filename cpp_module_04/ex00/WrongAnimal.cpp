#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "default constractor called for WrongAnimal !!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other)
{
    *this = other;
    std::cout << "copy constractor called for WrongAnimal !!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other)
{
    if( this == &other )
        return ( *this );
    
    this->_type = other._type;
    std::cout << "Copy assignment operator called for WrongAnimal" << std::endl;

    return ( *this );
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called for WrongAnimal !!" << std::endl;
}

std::string     WrongAnimal::getType() const
{
    return ( this->_type );
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes sounds " << std::endl;
}
