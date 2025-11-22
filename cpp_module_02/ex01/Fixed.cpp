#include "Fixed.hpp"

const int Fixed::_fractionalBitsNum = 8;

Fixed::Fixed( void )
{
    _fixedPointVal = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const float value )
{
    _fixedPointVal = Round(value * pow(2, 8));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
    _fixedPointVal = value * pow(2, 8);
    std::cout << "Int constructor called" << std::endl;
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
    return (_fixedPointVal);
}

void    Fixed::setRawBits( int const raw )
{
     _fixedPointVal = raw;
}

int Fixed::Round(float f)
{
    if (f - (int)f >= 0.5)
        return (int)(f + 1);
    return (int)f;
}

int Fixed::toInt( void ) const
{
    return (_fixedPointVal * pow(2,-8));
}

float Fixed::toFloat( void ) const
{
    return ((float)_fixedPointVal * pow(2,-8));
}
std::ostream &operator<<(std::ostream& os, const Fixed& obj)

{
    os << obj.toFloat();
    return ( os );
}
