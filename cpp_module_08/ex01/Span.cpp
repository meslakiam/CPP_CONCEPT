#include "Span.hpp"

Span::Span() : _array(0), _maxSize(0) {};

Span::Span(unsigned int n) : _array(0, 0), _maxSize(n) {}

Span::Span(const Span& other)
{
    this->_maxSize = other._maxSize;
    for (size_t i = 0; i < other._array.size(); i++)
        this->_array[i] = other._array[i];
}

Span&   Span::operator=(Span& other)
{
    std::cout << "hhh\n"; 
    if ( this == &other)
        return ( *this );

    this->_maxSize = other._maxSize;
    this->_array.resize(other._array.size());
    for (size_t i = 0; i < other._array.size(); i++)
        this->_array[i] = other._array[i];

    return ( *this );
}

Span::~Span() {}

void    Span::addNumber(unsigned int n)
{
    if ( this->_array.size() >= this->_maxSize)
        throw std::out_of_range("index out of range");
    this->_array.push_back(n);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; ++it)
        addNumber(*it);
}

int&    Span::operator[]( unsigned int idx)
{
    if ( idx >= _maxSize)
        throw std::out_of_range("index out of range");
    return ( this->_array[idx]);
}

int     Span::shortestSpan()
{
    if ( _array.size() <= 1 )
        throw std::runtime_error("Error");

    std::sort(_array.begin(), _array.end());

    size_t j = 0;
    int shortestSpan = _array[1] - _array[0];
    for (size_t i = 1; i < _array.size(); i++)
    {
        j = i - 1;
        int check = _array[i] - _array[j];
        if ( check < shortestSpan )
            shortestSpan = check;
    }
    return ( shortestSpan );
}

int     Span::longestSpan()
{
    if ( _array.size() <= 1 )
        throw std::runtime_error("Error");

    std::sort(_array.begin(), _array.end());

    return ( (*(_array.end() - 1)) - *(_array.begin()) );
}
