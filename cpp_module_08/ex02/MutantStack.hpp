#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class   MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;

        iterator end();
        iterator begin();

};

#include "MutantStack.tpp"

#endif