#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie Zombie::newZombie( std::string name )
{
    Zombie NewZombie;

    NewZombie._name = name;
    return (NewZombie);
}
