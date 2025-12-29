#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator    easyfind(T& a, int i);

#include "easyfind.tpp"

#endif