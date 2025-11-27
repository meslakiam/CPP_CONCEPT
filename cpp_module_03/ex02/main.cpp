#include "FragTrap.hpp"

void test1()
{
    FragTrap player1("ilyas");

    player1.attack("player 2");
    player1.takeDamage(5);
    player1.beRepaired(4);
    player1.attack("player 2");
}

void test2()
{
    FragTrap player1("ilyas");

    player1.attack("player 2");
    player1.takeDamage(11);
}

void test3()
{
    FragTrap player1("ilyas");
    FragTrap player2(player1);

    player2.attack("player 1");
    player2.takeDamage(0);
    player2.takeDamage(-1);
    player2.takeDamage(3);
    player2.beRepaired(4);

}

void test4()
{
    FragTrap player1;
    FragTrap player2("ilyas");

    player1.attack("player 3");
    player1 = player2;
    for (int i = 0; i < 51; i++)
        player1.beRepaired(1);
    player1.attack("player 4");
    player1.attack("player 5");
}

void test5()
{
    FragTrap player("ilyas");

    player.takeDamage(9);
    player.beRepaired(-3);
    player.takeDamage(1);
    player.attack("player 2");
    player.takeDamage(1);
}

void test6()
{
    FragTrap player("ilyas");

    player.attack("player 2");
    player.beRepaired(0);
    player.takeDamage(0);
    player.beRepaired(12345678);
    player.takeDamage(12345670);
    player.attack("player 2");
}

void test7()
{
    FragTrap player1;
    FragTrap player2("ilyas");

    player1.attack("player 3");
    player1 = player2;
    for (int i = 0; i < 101; i++)
        player1.takeDamage(1);
    player1.attack("player 4");
    player1.attack("player 5");
}

void test8()
{
    ClapTrap *C = new FragTrap("player 1");

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
