#include "Base.hpp"
#include "C.hpp"
#include "B.hpp"
#include "A.hpp"

Base*    generate(void)
{
    std::srand(std::time(0));

    int random = std::rand() % 3;
    std::cout << random << std::endl;
    switch (random)
    {
    case ClassA:
        return (new A);
    case ClassB:
        return (new B);
    case ClassC:
        return (new C);
    default:
        return (new A);
    }

}
