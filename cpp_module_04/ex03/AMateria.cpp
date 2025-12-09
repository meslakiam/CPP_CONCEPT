#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
}

AMateria::AMateria(AMateria& other)
{
    (void)other;
}

AMateria&   AMateria::operator=(AMateria& other)
{
    if (this == &other)
        return ( *this );

    this->_type = other._type;

    return ( *this );
}

AMateria::~AMateria() {}

std::string const   &AMateria::getType() const
{
    return ( this->_type );
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}
