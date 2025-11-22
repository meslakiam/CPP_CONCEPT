#include "Fixed.hpp"

const int Fixed::_fractionalBitsNum = 8;

Fixed::Fixed( void )
{
    _fixedPointVal = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if( this == &other )
        return ( *this );
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointVal = other.getRawBits();
    return ( *this );
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointVal);
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointVal = raw;
}
