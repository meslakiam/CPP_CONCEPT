#include "Span.hpp"

void    test1()
{
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void    test2()
{
    Span a(3);

    try
    {
        a.addNumber(5);
        a.addNumber(59);
        a.addNumber(-80);
        a.addNumber(597);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << a[0] << std::endl;
        std::cout << a[1] << std::endl;
        std::cout << a[2] << std::endl;
        std::cout << a[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test3()
{
    Span a( 100000);

    try
    {
        for (size_t i = 0; i <  100000; i++)
            a.addNumber(i + 1);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        for (size_t i = 0; i <  100000; i++)
            std::cout << a[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test4()
{
    Span a(6);

    a.addNumber(400);

    std::cout << a[0] << std::endl;
    try
    {
        std::cout << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    a.addNumber(100);
    a.addNumber(300);
    a.addNumber(401);
    try
    {
        std::cout << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test5()
{
    Span a(6);

    a.addNumber(400);

    std::cout << a[0] << std::endl;
    try
    {
        std::cout << a.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    a.addNumber(100);
    a.addNumber(300);
    a.addNumber(401);
    try
    {
        std::cout << a.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test6()
{
    Span a(9);

    int array[] = {2, 1, 4, 7, 3, 9, 5, 0, 6};
    std::vector<int> container(array, array + 9);

    a.addNumber(container.begin(), container.end());
    try
    {
        for (size_t i = 0; i <  9; i++)
            std::cout << a[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{

    test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    return 0;
}
