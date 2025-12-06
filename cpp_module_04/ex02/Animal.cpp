#include "Animal.hpp"

AAnimal::AAnimal()
{
    std::cout << "default constractor called for AAnimal !!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    *this = other;
    std::cout << "copy constractor called for AAnimal !!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if( this == &other )
        return ( *this );

    this->_type = other._type;
    std::cout << "Copy assignment operator called for AAnimal" << std::endl;

    return ( *this );
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor called for AAnimal !!" << std::endl;
}

std::string     AAnimal::getType() const
{
    return ( this->_type );
}

void    AAnimal::makeSound() const
{
    std::cout << "AAnimal makes sounds " << std::endl;
}
