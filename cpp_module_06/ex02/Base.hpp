#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

enum Type {
    ClassA,
    ClassB,
    ClassC
};

class   Base
{
    public:
        virtual ~Base() {};
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif