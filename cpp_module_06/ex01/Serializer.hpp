#ifndef SERISLIZER_HPP
#define SERISLIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class   Serializer {

    private:
        Serializer();
        Serializer(Serializer& other);
        Serializer& operator=(Serializer& other);
        ~Serializer();


    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif