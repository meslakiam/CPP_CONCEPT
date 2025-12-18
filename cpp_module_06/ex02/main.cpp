#include "C.hpp"
#include "B.hpp"
#include "A.hpp"

void    test1()
{
    Base *base;

    base = generate();

    identify(*base);
    identify(base);

    delete base;

}

void    test2()
{
    Base *base;

    std::cout  << "----------------------" << std::endl;
    base = new C;
    identify(*base);
    identify(base);
    delete base;
    std::cout  << "----------------------" << std::endl;

    base = new B;
    identify(*base);
    identify(base);
    delete base;
    std::cout  << "----------------------" << std::endl;

    base = new A;
    identify(*base);
    identify(base);
    delete base;
    std::cout  << "----------------------" << std::endl;
}

int main()
{
    test1();
    // test2();
    return 0;
}
