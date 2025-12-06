#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    std::cout << "default constractor called for Cat !!" << std::endl;
}

Cat::Cat(Cat& other) : Animal()
{
    *this = other;
    std::cout << "copy constractor called for Cat !!" << std::endl;
}

Cat& Cat::operator=(Cat& other)
{
    if( this == &other )
        return ( *this );

    this->_type = other._type;
    std::cout << "Copy assignment operator called for Cat" << std::endl;

    return ( *this );
}

Cat::~Cat()
{
    std::cout << "Destructor called for Cat !!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat makes sounds " << std::endl;
}
