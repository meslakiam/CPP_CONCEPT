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
        ~Fixed();
        Fixed&              operator=(const Fixed& other);
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        int                 getRawBits() const;
        void                setRawBits( int const raw );
 
        static Fixed&       max(const Fixed& f1, const Fixed& f2);
        static Fixed&       min(const Fixed& f1, const Fixed& f2);
        static Fixed&       max(Fixed& f1, Fixed& f2);
        static Fixed&       min(Fixed& f1, Fixed& f2);

        //          ARITHMETIC OPERATORS
        Fixed               operator*(const Fixed& obj);
        Fixed               operator/(const Fixed& obj);
        Fixed               operator+(const Fixed& obj);
        Fixed               operator-(const Fixed& obj);

        //         COMPARISON OPERATORS
        bool                operator<(const Fixed& obj);
        bool                operator<=(const Fixed& obj);
        bool                operator>(const Fixed& obj);
        bool                operator>=(const Fixed& obj);
        bool                operator==(const Fixed& obj);
        bool                operator!=(const Fixed& obj);

        //         INCREMENT / DECREMENT
        Fixed&              operator++( void );
        Fixed               operator++( int );
        Fixed&              operator--( void );
        Fixed               operator--( int );

};
std::ostream &operator<<(std::ostream& os, const Fixed& obj);

#endif
