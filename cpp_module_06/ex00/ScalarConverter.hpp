#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP 

#include <iostream>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <iomanip>


class   ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter& other);
        ScalarConverter&    operator=(ScalarConverter& other);
        ~ScalarConverter();

        static bool     IsFloatNum(std::string& literal);
        static bool     IsDoubleNum(std::string& literal);
        static char     IsChar(std::string& literal, int i);

        static char    ConvertToCHAR(std::string& literal);
        static int     ConvertToINT(std::string& literal);
        static float   ConvertToFLOAT(std::string& literal);
        static double  ConvertToDOUBLE(std::string& literal);
        static bool    ConvertToPseudo(std::string& literal);

        static void    PrintToOutput(char c, int num, float numf, double numd, std::string* error);

    public:

        static void convert(std::string& literal);

        class ERRORMSG : public std::exception {
            private:
                std::string _errorMsg;
            
            public:
                ERRORMSG(std::string errorMsg);
                virtual ~ERRORMSG() throw() {};
                const char* what() const throw();
        };

};


#endif