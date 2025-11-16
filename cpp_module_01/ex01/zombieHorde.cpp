#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie* Hord;

    Hord = new Zombie[N];
    for(int i = 0; i < N; i++)
        Hord[i] = newZombie(name);
    return (Hord);
}
