#include "RPN.hpp"


int main(int argc, char const *argv[])
{
    if ( argc < 2)
        return 0;

    std::list<string> l_args;
    for (int i = 1; i < argc; i++)
        l_args.push_back(argv[i]);
    std::cout << "\n---------------------------\n" ;
    for (List::iterator i = l_args.begin(); i != l_args.end(); i++)
    {
        std::cout << *i << " " ;
    }
    std::cout << "\n---------------------------\n" ;
    
    
    try
    {
        RPN expressions;

        long n = expressions.evaluateRPN(l_args);
        std::cout << "resulte = " << n << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
    
    return 0;
}
