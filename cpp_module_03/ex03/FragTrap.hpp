#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
        FragTrap(int hitPoint,int  attackDamage);

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap& other);
        FragTrap& operator=(FragTrap& other);
        ~FragTrap();

        void    highFivesGuys(void);
};

#endif