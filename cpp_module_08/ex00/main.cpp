#include "easyfind.hpp"
#include <vector>
#include <deque>

void    test1()
{
    int array[] = {1, 2, 3, 42};
    std::vector<int> container(array, array + 4);
    int val = 42;

    try
    {
        std::vector<int>::iterator it = easyfind(container, val);
        std::cout << "found " << *it << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test2()
{
    int array[] = {-1, 34, 676, 42};
    int val = 12;

    std::vector<int> container(array, array + 4);
    try
    {
        std::vector<int>::iterator it = easyfind(container, val);
        std::cout << "found " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test3()
{
    int array[] = {1, 2, 3, 42};
    std::deque<int> container(array, array + 4);
    int val = 42;

    try
    {
        std::deque<int>::iterator it = easyfind(container, val);
        std::cout << "found " << *it << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    test1();
    // test2();
    // test3();
}
