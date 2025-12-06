#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat& other);
        Cat& operator=(Cat& other);
        ~Cat();

        void makeSound() const;
};

#endif