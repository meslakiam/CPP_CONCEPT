#include "Fixed.hpp"


std::ostream &operator<<(std::ostream& os, const Fixed& obj)

{
    os << obj.toFloat();
    return ( os );
}

//         INCREMENT / DECREMENT
// ++i
Fixed&              Fixed::operator++( void )
{

    this->_fixedPointVal += 1;
    return ( *this );
}

// i++
Fixed              Fixed::operator++( int )
{
    Fixed old(*this);

    this->_fixedPointVal += 1;
    return (old);
}

Fixed&              Fixed::operator--( void )
{
    this->_fixedPointVal -= 1;
    return ( *this );
}

Fixed              Fixed::operator--( int )
{
    Fixed old(*this);

    this->_fixedPointVal -= 1;
    return (old);
}

//          ARITHMETIC OPERATORS

Fixed              Fixed::operator*(const Fixed& other)
{
    Fixed resulte(this->toFloat() * other.toFloat());
    return ( resulte );
   
}

Fixed              Fixed::operator/(const Fixed& other)
{
    if(other.toInt() == 0)
    {
        std::cout << "Division By 0 Unacceptable" << std::endl;
        return ((Fixed&)other);
    }
    Fixed resulte(this->toFloat() / other.toFloat());
    return ( resulte );
}

Fixed              Fixed::operator+(const Fixed& other)
{
    Fixed resulte(this->toFloat() + other.toFloat());
    return ( resulte );
}

Fixed              Fixed::operator-(const Fixed& other)
{
    Fixed resulte(this->toFloat() - other.toFloat());
    return ( resulte );
}

//         COMPARISON OPERATORS

bool                Fixed::operator<(const Fixed& other)
{
    return (this->getRawBits() < other.getRawBits());
}

bool                Fixed::operator<=(const Fixed& other)
{
    return (this->getRawBits() <= other.getRawBits());
}

bool                Fixed::operator>(const Fixed& other)
{
    return (this->getRawBits() > other.getRawBits());
}

bool                Fixed::operator>=(const Fixed& other)
{
    return (this->getRawBits() >= other.getRawBits());
}

bool                Fixed::operator==(const Fixed& other)
{
    return (this->getRawBits() == other.getRawBits());
}

bool                Fixed::operator!=(const Fixed& other)
{
    return (this->getRawBits() != other.getRawBits());
}
