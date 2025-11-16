#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("gun");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("knife");
        bob.attack();
    }
    {
        Weapon club = Weapon("knife");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("gun");
        jim.attack();
    }
    return 0;
}
