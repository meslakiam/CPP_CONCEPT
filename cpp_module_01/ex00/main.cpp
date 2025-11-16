
#include "Zombie.hpp"

void    test1( void )
{
    Zombie Z("imeslaki");
    Zombie *First;

    Z.announce();
    First = Z.newZombie("ilyas");
    First->announce();
    First->randomChump("meslakiam");
    delete First;
}

void    test2( void )
{
    Zombie Z("King");
    Zombie *Queen;

    Z.announce();
    Queen = Z.newZombie("Queen");
    Queen->announce();
    Z.randomChump("Follower 1");
    Z.randomChump("Follower 2");
    Z.randomChump("Follower 3");

    delete Queen;
}

int main()
{
    // test1();
    test2();
}
