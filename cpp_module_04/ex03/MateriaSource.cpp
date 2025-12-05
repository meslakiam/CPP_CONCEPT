#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        this->_templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource& other)
{
    for (size_t i = 0; i < 4; i++)
        this->_templates[i] = 0;
    *this = other;
}

MateriaSource&  MateriaSource::operator=(MateriaSource& other)
{
    if(this == &other )
        return ( *this );

    for (size_t i = 0; i < 4; i++)
    {
        if( this->_templates[i] )
            delete this->_templates[i];
    }
    for (size_t i = 0; i < 4; i++)
    {
        if( other._templates[i] )
            this->_templates[i] = other._templates[i]->clone();
        else
            this->_templates[i] = 0;
    }
    return ( *this );
}
MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        if( this->_templates[i] )
            delete this->_templates[i];
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if(this->_templates[i] == 0)
        {
            this->_templates[i] = m;
            return ;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if( this->_templates[i] && this->_templates[i]->getType() == type)
            return (this->_templates[i]->clone());
    }
    return (0);
}
