#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    Zombie newZombie;
    
    newZombie._name = name;
    std::cout << newZombie._name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
