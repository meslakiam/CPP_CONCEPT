#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
typename T::iterator    easyfind(T& container, int val)
{
    typename T::iterator it = std::find( container.begin(), container.end(), val);
    if ( it == container.end() )
        throw std::runtime_error("error");

    return ( it );
}

#endif