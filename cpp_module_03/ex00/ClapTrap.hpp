#ifndef CLAPTRA_HPP
#define CLAPTRA_HPP

#include <iostream>

class ClapTrap {

    private:
        std::string _name;
        int         _hitPoint;
        int         _energyPoint;
        int         _attackDamage;

    protected:
    // ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
    public:
        ClapTrap();
        ClapTrap(std::string name);
        
        ClapTrap(ClapTrap& other);
        ClapTrap& operator=(ClapTrap& other);
        ~ClapTrap();

        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

};

#endif
