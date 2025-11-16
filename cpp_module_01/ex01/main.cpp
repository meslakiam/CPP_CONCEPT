#include "Zombie.hpp"

void    test1( void )
{
    Zombie Z;
    Zombie *Hord;

    Hord = Z.zombieHorde(5, "hhhh");

    for(int i = 0; i < 5; i++)
        Hord->announce();
    delete[] Hord;
}

int main()
{
    test1();
    return 0;
}
