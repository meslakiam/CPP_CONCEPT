#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>

class Array {

    private:
        T   *_data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array& other);
        Array&  operator=(Array& other);
        ~Array();

        T&  operator[]( unsigned int idx );
        size_t  size() const;
};


#include "Array.tpp"
#endif