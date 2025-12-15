#include "ScalarConverter.hpp"


int main(int argc, char const *argv[])
{
    if ( argc == 2)
    {
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    }
    else
        std::cout << "Invalid ARG" << std::endl;

    return 0;
}
