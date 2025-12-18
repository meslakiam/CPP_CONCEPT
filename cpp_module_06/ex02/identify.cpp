#include "C.hpp"
#include "B.hpp"
#include "A.hpp"


void identify(Base* p)
{

    if (dynamic_cast<A*>(p))
        std::cout << "origine type is class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "origine type is class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "origine type is class C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;

}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "origine type is class A" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "origine type is class B" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "origine type is class C" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}
    
}
