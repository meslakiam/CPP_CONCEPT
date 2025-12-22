#include "iter.hpp"

void    func(int i)
{
    std::cout << i << " ";
}

void test1()
{
    int array[] = {1, 2, 3, 4};

    iter(array, 4, print<int&>);
}

void    test2()
{
    char array[] = "hello world";

    iter(array, 10, print<char>);
}

void    test3()
{
    double array[] = {1.2, 3.4, 0.56, 42.42 };

    iter(array, 4, print<double>);
}

void    test4()
{
    std::string array[] = {"hello", "world", "42", "1337" };
    iter(array, 4, print<std::string>);
}

void    test5()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    iter(array, 7, func);
}

int main()
{
    test1();
    // test2();
    // test3();
    // test4();
    // test5();

    return 0;
}
