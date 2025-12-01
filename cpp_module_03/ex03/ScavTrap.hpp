#ifndef SCAVTRAP_HPP 
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:
        ScavTrap(int energyPoint);

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& other);
        ScavTrap& operator=(ScavTrap& other);
        ~ScavTrap();

        virtual void        attack(const std::string& target);
        void        guardGate();

};

#endif