#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{

    if ( argc <= 1 )
    {
        std::cout << "there is no numbers to sort !!\n";
        return 0;
    }

    std::vector<std::string> v_args;
    for (int i = 1; i < argc; i++)
        v_args.push_back(argv[i]);
    try
    {
        PmergeMe   p(v_args);
        p.sort();
 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
