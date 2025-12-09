#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "default constractor called for WrongCat !!" << std::endl;
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal()
{
    *this = other;
    std::cout << "copy constractor called for WrongCat !!" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
    if( this == &other )
        return ( *this );

    this->_type = other._type;
    std::cout << "Copy assignment operator called for WrongCat" << std::endl;

    return ( *this );
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called for WrongCat !!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat makes sounds " << std::endl;
}
