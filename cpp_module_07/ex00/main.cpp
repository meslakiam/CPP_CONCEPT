#include "whatever.hpp"


void test1()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}

void    test2()
{
    {
        std::cout << "-------------------------------------------------------" << std::endl;
        int i = 5;
        int g = 7;
        std::cout << "this is i befor: " << i << " | this is g befor: " << g << std::endl;
        swap(i, g);
        std::cout << "this is i after: " << i << " | this is g after: " << g << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    {
        std::string i = "hello";
        std::string g = "world";
        std::cout << "this is i befor: " << i << " | this is g befor: " << g << std::endl;
        swap(i, g);
        std::cout << "this is i after: " << i << " | this is g after: " << g << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    {
        float i = 1.3f;
        float g = 4.6f;
        std::cout << "this is i befor: " << i << " | this is g befor: " << g << std::endl;
        swap(i, g);
        std::cout << "this is i after: " << i << " | this is g after: " << g << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }

    {
        double i = 5.7;
        double g = 10.3;
        std::cout << "this is i befor: " << i << " | this is g befor: " << g << std::endl;
        swap(i, g);
        std::cout << "this is i after: " << i << " | this is g after: " << g << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
}

void    test3()
{
    {
        int res = min(5, 7);
        std::cout << "int res = " << res << std::endl;
    }
    {
        std::string res = min("hello", "world");
        std::cout << "string res = " << res << std::endl;
    }
    {
        float res = min(1.3f, 4.6f);
        std::cout << "float res = " << res << std::endl;
    }
    {

        double res = min(5.7, 10.3);
        std::cout << "double res = " << res << std::endl;
    }
}

void    test4()
{
    {
        int res = max(5, 7);
        std::cout << "int res = " << res << std::endl;
    }
    {
        std::string res = max("hello", "world");
        std::cout << "string res = " << res << std::endl;
    }
    {
        float res = max(1.3f, 1.6f);
        std::cout << "float res = " << res << std::endl;
    }
    {

        double res = max(5.7, 10.3);
        std::cout << "double res = " << res << std::endl;
    }
}



int main()
{
    test1();
    // test2();
    // test3();
    // test4();
    return 0;
}
