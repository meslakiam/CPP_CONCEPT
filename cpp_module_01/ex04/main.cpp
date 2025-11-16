#include "FileReplacer.hpp"

int PrintError( void )
{
    std::cout << "Error:\n  can't open file" << std::endl;
    return (1);
}

int main(int argc, char const *argv[])
{
    if(argc == 4)
    {
        std::string FileName = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        FileReplacer Replacer(FileName);

        if(!Replacer.Open())
            return(PrintError());
        Replacer.Replace(s1, s2);
        if(!Replacer.WriteToFile())
            return(PrintError());
    } 
    else
        std::cout << "Error:  Invalid Argument" << std::endl;
    return 0;
}
