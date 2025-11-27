#include "Fixed.hpp"

const int Fixed::_fractionalBitsNum = 8;

Fixed::Fixed( void )
{
    _fixedPointVal = 0;
}

Fixed::Fixed( const float value )
{
    _fixedPointVal = Round(value * pow(2, 8));
}

Fixed::Fixed( const int value )
{
    _fixedPointVal = value * pow(2, 8);
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if( this == &other )
        return ( *this );
    this->_fixedPointVal = other.getRawBits();
    return ( *this );
}

Fixed::~Fixed( void )
{
    
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

Fixed&       Fixed::max(Fixed& f1, Fixed& f2)
{
    if( f1.getRawBits() > f2.getRawBits() )
        return ( f1 );
    return ( f2 );
}

Fixed&       Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if( f1.getRawBits() > f2.getRawBits() )
        return ( (Fixed&)f1 );
    return ( (Fixed&)f2 );
}

Fixed&       Fixed::min(Fixed& f1, Fixed& f2)
{
    if( f1.getRawBits() < f2.getRawBits() )
        return ( f1 );
    return ( f2 );
}

Fixed&       Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if( f1.getRawBits() < f2.getRawBits() )
        return ( (Fixed&)f1 );
    return ( (Fixed&)f2 );
}
