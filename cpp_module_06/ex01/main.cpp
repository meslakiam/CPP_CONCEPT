#include "Serializer.hpp"


int main()
{
    Data    data;
    Data    *save;
    uintptr_t ptr;

    data.name = "data";

    std::cout << data.name << std::endl;
    ptr = Serializer::serialize(&data);
    std::cout << "--------------------------" << std::endl;

    save = Serializer::deserialize(ptr);

    std::cout << data.name << std::endl;
    std::cout << save->name << std::endl;
    std::cout << "--------------------------" << std::endl;

    save->name = "hi";

    std::cout << data.name << std::endl;
    std::cout << save->name << std::endl;
}
