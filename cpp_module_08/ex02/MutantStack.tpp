#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::begin()
{
    return ( this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::end()
{
    return ( this->c.end() );
}

#endif