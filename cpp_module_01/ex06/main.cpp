#include "Harl.hpp"

int main(int argc, char const *argv[])
{

    if(argc == 2)
    {
        std::string Level = argv[1];
        Harl H;

        H.FilterComplain(Level);
    }
    else
        std::cout << "Error:  Invalid Argument" << std::endl;
    return 0;
}