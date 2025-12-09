#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->_type = "Dog";
    this->_brain = new Brain;
    std::cout << "default constractor called for Dog !!" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal()
{
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    std::cout << "copy constractor called for Dog !!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if( this == &other )
        return ( *this );

    this->_type = other._type;
    *this->_brain = *other._brain;
    std::cout << "Copy assignment operator called for Dog" << std::endl;

    return ( *this );
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Destructor called for Dog !!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog makes sounds " << std::endl;
}
