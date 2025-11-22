#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointVal;
        static const int _fractionalBitsNum;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int     getRawBits() const;
        void    setRawBits( int const raw );

};


#endif