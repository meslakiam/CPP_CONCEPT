#include "Bureaucrat.hpp"

void    test1()
{
    try
    {
        std::cout << "----------------------------" << std::endl;
        Bureaucrat b1("Bureaucrat 1", 2);
        std::cout << b1 << std::endl;
        std::cout << b1.GetName() << std::endl;
        b1.IncrementGrade(1);
        std::cout << b1 << std::endl;
        std::cout << "----------------------------" << std::endl;

        Bureaucrat b2("Bureaucrat 2", -11);
        std::cout << b2 << std::endl;
        std::cout << b2.GetName() << std::endl;
        b2.IncrementGrade(1);
        std::cout << b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

void    test2()
{
    try
    {
        std::cout << "----------------------------" << std::endl;
        Bureaucrat b1("Bureaucrat", 150);
        std::cout << b1 << std::endl;
        b1.IncrementGrade(100);
        std::cout << b1 << std::endl;
        b1.DecrementGrade(50);
        std::cout << b1 << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

void    test3()
{
    try
    {
        std::cout << "----------------------------" << std::endl;
        Bureaucrat b1("Bureaucrat", 1);
        std::cout << b1 << std::endl;
        std::cout << "----------------------------" << std::endl;

        Bureaucrat b2(b1);
        std::cout << b2 << std::endl;
        b2.DecrementGrade(324234234);
        std::cout << b2 << std::endl;
        std::cout << "the Grade is: " << b2.GetGrade() << std::endl;
        b2.DecrementGrade(-324234234);
        std::cout << b2 << std::endl;
        std::cout << "the Grade is: " << b2.GetGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}


int main()
{
    test1();
    // test2();
    // test3();

    return 0;
}
