#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(0)
{
    if ( n == 0)
        return ;

    this->_data = new T[n]();
    this->_size = n;

}

template<typename T>
Array<T>::Array(Array& other) : _data(NULL), _size(0)
{
    if ( other._size == 0)
        return ;

    this->_data = new T[other._size]();
    this->_size = other._size;
}

template<typename T>
Array<T>&  Array<T>::operator=(Array& other)
{
    if ( this == &other || other._size == 0)
        return ( *this );
    
    this->_data = new T[this->_size]();
    for (size_t i = 0; i < this->_size; i++)
        this->_data[i] = other._data[i];

    this->_size = other._size;
    return ( *this );
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->_data;
}

template<typename T>
T&  Array<T>::operator[](unsigned int idx)
{
    if (idx >= this->_size)
        throw std::out_of_range("index out of bounds");

    return ( this->_data[idx] );
}

template<typename T>
size_t  Array<T>::size() const
{
    return ( this->_size );
}


#endif