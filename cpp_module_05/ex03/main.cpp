#include "Intern.hpp"

void test1()
{
    Intern someRandomIntern;

    AForm* rrf;
    AForm* ppf;
    AForm* scf;
    AForm* error;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    error = someRandomIntern.makeForm("invalid form", "Bender");

    delete rrf;
    delete ppf;
    delete scf;
}

void test2()
{
    Intern someRandomIntern;
    Bureaucrat b1("suuny", 1);
    Bureaucrat b2("jon", 40);
    Bureaucrat b3("jack", 140);

    AForm* rrf;
    AForm* ppf;
    AForm* scf;

    std::cout << "-------------------------------" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "max");
    scf = someRandomIntern.makeForm("shrubbery creation", "bob");
    std::cout << "-------------------------------" << std::endl;

    b1.signForm(*ppf);
    b2.signForm(*rrf);
    b3.signForm(*scf);
    std::cout << "-------------------------------" << std::endl;

    b1.executeForm(*ppf);
    b2.executeForm(*rrf);
    b3.executeForm(*scf);
    std::cout << "-------------------------------" << std::endl;

    delete rrf;
    delete ppf;
    delete scf;
}

int main()
{
    test1();
    // test2();

    return 0;
}
