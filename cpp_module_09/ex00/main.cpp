#include "BitcoinExchange.hpp"


int main(int argc, char const *argv[])
{
    if ( argc == 2 )
    {
        try
        {
            

            btc(argv[1]);


        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        


    }
    else
        std::cout << "Invalid Argument !!\n";
    return 0;
}
