#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1()
{
    Bureaucrat b1("jon", 70);
    Bureaucrat b2("bob", 20);
    Bureaucrat b3("max", 150);
    Bureaucrat b4("sunny", 1);

    PresidentialPardonForm  pref("target");

    std::cout << "-------------------------------" << std::endl;
    b1.signForm(pref);
    b2.signForm(pref);
    b3.signForm(pref);
    b4.signForm(pref);
    std::cout << "-------------------------------" << std::endl;
    
    b1.executeForm(pref);
    b2.executeForm(pref);
    b3.executeForm(pref);
    b4.executeForm(pref);
    std::cout << "-------------------------------" << std::endl;

    try
    {
        pref.execute(b4);
        pref.execute(b2);
        pref.execute(b3);
        pref.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to execute " << pref.getName() << '\n';
    }
}

void    test2()
{
    Bureaucrat b1("jon", 70);
    Bureaucrat b2("bob", 20);
    Bureaucrat b3("max", 150);
    Bureaucrat b4("sunny", 1);

    RobotomyRequestForm  robf("target");

    std::cout << "-------------------------------" << std::endl;
    b1.signForm(robf);
    b2.signForm(robf);
    b3.signForm(robf);
    b4.signForm(robf);
    std::cout << "-------------------------------" << std::endl;
    
    b1.executeForm(robf);
    b2.executeForm(robf);
    b3.executeForm(robf);
    b4.executeForm(robf);
    std::cout << "-------------------------------" << std::endl;

    try
    {
        robf.execute(b4);
        robf.execute(b2);
        robf.execute(b3);
        robf.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to execute " << robf.getName() << '\n';
    }
}

void    test3()
{
    Bureaucrat b1("jon", 70);
    Bureaucrat b2("bob", 20);
    Bureaucrat b3("max", 150);
    Bureaucrat b4("sunny", 1);

    ShrubberyCreationForm  shrf("target");
    ShrubberyCreationForm  shrf2("shrubbery");

    std::cout << "-------------------------------" << std::endl;
    b1.signForm(shrf);
    b2.signForm(shrf);
    b3.signForm(shrf);
    b4.signForm(shrf);
    std::cout << "-------------------------------" << std::endl;
    
    b1.executeForm(shrf);
    b2.executeForm(shrf);
    b3.executeForm(shrf);
    b4.executeForm(shrf);
    std::cout << "-------------------------------" << std::endl;

    try
    {
        shrf2.execute(b4);
        shrf2.execute(b2);
        shrf2.execute(b3);
        shrf2.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to execute " << shrf.getName() << '\n';
    }
}

void    test4()
{
    Bureaucrat b1("jon", 70);
    Bureaucrat b2("bob", 20);
    Bureaucrat b3("max", 150);
    Bureaucrat b4("sunny", 1);

    ShrubberyCreationForm  shrf("target");
    ShrubberyCreationForm  shrf2("shrubbery");

    std::cout << "-------------------------------" << std::endl;
    try
    {
        shrf2.execute(b4);
        shrf2.execute(b2);
        shrf2.execute(b3);
        shrf2.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to execute " << shrf.getName() << '\n';
    }

    std::cout << "-------------------------------" << std::endl;
    b1.signForm(shrf);
    b2.signForm(shrf);
    b3.signForm(shrf);
    b4.signForm(shrf);

    std::cout << "-------------------------------" << std::endl;
    b1.executeForm(shrf);
    b2.executeForm(shrf);
    b3.executeForm(shrf);
    b4.executeForm(shrf);
    std::cout << "-------------------------------" << std::endl;
}

void    test5()
{
    Bureaucrat b1("jon", 70);
    Bureaucrat b2("bob", 20);
    Bureaucrat b3("max", 150);
    Bureaucrat b4("sunny", 1);

    PresidentialPardonForm  pref("target");

    std::cout << "-------------------------------" << std::endl;
    try
    {
        std::cout << "form sign state is: " << pref.getSign() << std::endl ;
        pref.beSigned(b4);
        std::cout << "form sign state is: " << pref.getSign() << std::endl ;
        pref.beSigned(b2);
        std::cout << "form sign state is: " << pref.getSign() << std::endl ;
        pref.beSigned(b3);
        std::cout << "form sign state is: " << pref.getSign() << std::endl ;
        pref.beSigned(b1);
        std::cout << "form sign state is: " << pref.getSign() << std::endl ;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to signed " << pref.getName() << '\n';
    }
    std::cout << "-------------------------------" << std::endl;
    
    try
    {
        pref.execute(b4);
        pref.execute(b2);
        pref.execute(b3);
        pref.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " to execute " << pref.getName() << '\n';
    }

    std::cout << "-------------------------------" << std::endl;
    b1.executeForm(pref);
    b2.executeForm(pref);
    b3.executeForm(pref);
    b4.executeForm(pref);
    std::cout << "-------------------------------" << std::endl;

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
