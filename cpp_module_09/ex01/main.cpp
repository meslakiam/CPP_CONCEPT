#include "RPN.hpp"


int main(int argc, char const *argv[])
{
    if ( argc == 2)
    {
        string args;
        args = argv[1]; 
        try
        {
            RPN expressions;

            long res = expressions.evaluateRPN(args);
            std::cout << res << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error:\n   bad input" << std::endl ;
    
    return 0;
}
