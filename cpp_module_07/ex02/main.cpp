#include "Array.hpp"

void test1()
{
    std::cout << "=== Default constructor ===" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::cout << "=== Sized constructor (int) ===" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    Array<int> b(5);
    std::cout << "size: " << b.size() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

}

void    test2()
{
    Array<int> a(3);

    try
    {
        std::cout << "a[0] = " << a[0] << std::endl;
        std::cout << "a[1] = " << a[1] << std::endl;
        std::cout << "a[2] = " << a[2] << std::endl;
        std::cout << "a[3] = " << a[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test3()
{
    Array<int> a(3);

    a[0] = 6;
    a[1] = 21;
    a[2] = -5;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
}

void    test4()
{
    Array<std::string> str(3);

    str[0] = "hello";
    str[1] = "world";
    str[2] = "hi";

    for (unsigned int i = 0; i < str.size(); i++)
        std::cout << "str[" << i << "] = " << str[i] << std::endl;
}

void    test5()
{
    Array<float> a(3);

    a[0] = 1.4f;
    a[1] = 2.1f;
    a[2] = -234.3f;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    std::cout << "---------------------" << std::endl;

    a[0] = 0;
    a[1] = 21.4f;
    a[2] = -1;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
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
