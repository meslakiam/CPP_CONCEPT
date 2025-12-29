#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class   Span {

    private:
        std::vector<int> _array;
        size_t  _maxSize;
        Span();

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span&   operator=(Span& other);
        ~Span();

        void    addNumber( unsigned int n);
        void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longestSpan();

        int&    operator[](unsigned int idx);
};

#endif