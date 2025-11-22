#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed
{
    private:
        int                 _fixedPointVal;
        static const int    _fractionalBitsNum;
        int                 Round(float f);

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float fNumValue);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        int                 getRawBits() const;
        void                setRawBits( int const raw );

};
std::ostream &operator<<(std::ostream& os, const Fixed& obj);

#endif
