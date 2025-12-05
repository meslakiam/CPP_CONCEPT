#ifndef MATRIASOURCE_HPP
#define MATRIASOURCE_HPP

#include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    private:
        AMateria *_templates[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource& other);
        MateriaSource&  operator=(MateriaSource& other);
        virtual ~MateriaSource();

        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
};

#endif