#include "Form.hpp"

void    test1()
{
    try 
    {
        std::cout << "----------------------------" << std::endl;
        Bureaucrat b1("bob", 5);
        Bureaucrat b2("jon", 10);
        Form       f1("contract", 10, 7);

        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
        f1.beSigned(b1);
        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
        f1.beSigned(b2);
        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    
}

void    test2()
{
    try 
    {
        std::cout << "----------------------------" << std::endl;
        Bureaucrat b1("bob", 5);
        Bureaucrat b2("jon", 10);
        Form       f1("contract", 8, 7);

        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
        f1.beSigned(b1);
        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
        f1.beSigned(b2);
        std::cout << f1 << std::endl;
        std::cout << f1.getSign() << std::endl; 
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    
}

void    test3()
{
    std::cout << "----------------------------" << std::endl;
    try
    {
        Bureaucrat  b1("bob", 1);
        Bureaucrat  b2("jon", 10);
        Form        f("contract", 9, 2);

        b1.signForm(f);
        b2.signForm(f);
    }
    catch (std::exception&  e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

void    test4()
{
    std::cout << "----------------------------" << std::endl;
    try
    {
        Bureaucrat  b1("bob", 1);
        Bureaucrat  b2("jon", 5);
        Form        f("contract", 9, 2);

        std::cout << f << std::endl;
        f.beSigned(b1);
        std::cout << f << std::endl;

        b2.signForm(f);
        b1.signForm(f);
        b1.signForm(f);
        b2.signForm(f);
    }
    catch (std::exception&  e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}


void    test5()
{
    std::cout << "----------------------------" << std::endl;
    try
    {
        Bureaucrat  b1("bob", 1);
        Bureaucrat  b2("jon", 5);
        Form        f("contract", 1, 2);

        std::cout << f << std::endl;
        f.beSigned(b1);
        std::cout << f << std::endl;

        b2.signForm(f);
        b1.signForm(f);
        b1.signForm(f);
        b2.signForm(f);
    }
    catch (std::exception&  e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

void    test6()
{
    std::cout << "----------------------------" << std::endl;
    try
    {
        Bureaucrat  b1("bob", 1);
        Bureaucrat  b2("jon", 5);
        Form        f("contract", 1, 2);

        std::cout << f << std::endl;
        f.beSigned(b2);
        std::cout << f << std::endl;

        b2.signForm(f);
        b1.signForm(f);
        b1.signForm(f);
        b2.signForm(f);
    }
    catch (std::exception&  e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
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
