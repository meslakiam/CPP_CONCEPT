#include "ClapTrap.hpp"

void test1()
{
    ClapTrap player1("ilyas");

    player1.attack("player 2");
    player1.takeDamage(5);
    player1.beRepaired(4);
    player1.attack("player 2");
}

void test2()
{
    ClapTrap player1("ilyas");

    player1.attack("player 2");
    player1.takeDamage(11);
}

void test3()
{
    ClapTrap player1("ilyas");
    ClapTrap player2(player1);

    player2.attack("player 1");
    player2.takeDamage(0);
    player2.takeDamage(-1);
    player2.takeDamage(3);
    player2.beRepaired(4);

}

void test4()
{
    ClapTrap player1;
    ClapTrap player2("ilyas");

    player1.attack("player 3");
    player1 = player2;
    for (int i = 0; i < 11; i++)
        player1.beRepaired(1);
    player1.attack("player 4");
    player1.attack("player 5");
    player1.takeDamage(2);
}

void test5()
{
    ClapTrap player("ilyas");

    player.takeDamage(9);
    player.beRepaired(-3);
    player.takeDamage(1);
    player.attack("player 2");
    player.takeDamage(1);
    player.beRepaired(3);
}

void test6()
{
    ClapTrap player("ilyas");

    player.attack("player 2");
    player.beRepaired(0);
    player.takeDamage(0);
    player.beRepaired(12345678);
    player.takeDamage(12345670);
    player.attack("player 2");
}

void test7()
{
    ClapTrap player1;
    ClapTrap player2("ilyas");

    player1.attack("player 3");
    player1 = player2;
    for (int i = 0; i < 11; i++)
        player1.takeDamage(1);
    player1.attack("player 4");
    player1.attack("player 5");
}

void test8()
{
    ClapTrap *C = new ClapTrap("player 1");

    C->attack("player 2");
    C->takeDamage(30);
    delete C;
}

int main( void )
{
    test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    return 0;
}
