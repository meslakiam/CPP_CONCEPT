#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
    
    std::cout << "default constractor called for Brain !!" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "copy constractor called for Brain !!" << std::endl;
}

Brain&  Brain::operator=(const Brain& other)
{
    if(this == &other)
        return ( *this );

    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    std::cout << "Copy assignment operator called for Brain" << std::endl;

    return ( *this );
}

Brain::~Brain()
{
    std::cout << "Destructor called for Brain !!" << std::endl;
}
