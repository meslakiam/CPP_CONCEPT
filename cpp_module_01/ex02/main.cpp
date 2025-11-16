#include <iostream>

int main()
{
    std::string String = "HI THIS IS BRAIN";
    std::string* StringPTR = &String;
    std::string& stringREF = String;

    std::cout << "The memory address of the string variable is: " << &String << std::endl;
    std::cout << "The memory address held by stringPTR is: " << StringPTR << std::endl;
    std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;

    std::cout << "\nThe value of the string variable is: " << String << std::endl;
    std::cout << "The value pointed to by stringPTR is: " << *StringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;

    return 0;
}
