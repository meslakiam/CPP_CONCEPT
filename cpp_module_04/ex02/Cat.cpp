#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "default constractor called for Cat !!" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal()
{
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    std::cout << "copy constractor called for Cat !!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if( this == &other )
        return ( *this );

    this->_type = other._type;
   *this->_brain = *other._brain;
    std::cout << "Copy assignment operator called for Cat" << std::endl;

    return ( *this );
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Destructor called for Cat !!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat makes sounds " << std::endl;
}
