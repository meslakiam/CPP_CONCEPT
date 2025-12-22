#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>

void    iter(T  *array,const size_t lenght, F func)
{
    for (size_t i = 0; i < lenght; i++)
    {
        func(array[i]);
    }
}

template<typename T>

void    print(T c)
{
    std::cout << c << " ";
}
#endif