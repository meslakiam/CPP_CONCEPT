#include<iostream>

void    ToUpperAndPrint(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(isalpha(str[i]) && islower(str[i]))
            str[i] = toupper(str[i]);
        std::cout << str[i];
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;

    i = 1;
    if(argc > 1)
    {
        while (argv[i])
        {
            ToUpperAndPrint(argv[i]);
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
