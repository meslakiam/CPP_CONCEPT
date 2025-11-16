#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class   Zombie{

    private:
        std::string     _name;

    public:
        Zombie*         zombieHorde( int N, std::string name );
        Zombie          newZombie( std::string name );
        void            announce( void );
};

#endif