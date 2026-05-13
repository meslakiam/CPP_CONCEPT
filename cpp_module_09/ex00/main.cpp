#include "BitcoinExchange.hpp"


int main(int argc, char const *argv[])
{
    if ( argc == 2 )
    {
        try
        {
            string arg = argv[1];
            btc bitcoin;
            bitcoin.runExchange(arg);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "Invalid Argument !!\n";
    return 0;
}
